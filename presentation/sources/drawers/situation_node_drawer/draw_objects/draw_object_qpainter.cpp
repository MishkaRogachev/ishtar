#include "draw_object_qpainter.h"

#include <QPainter>
#include <QDebug>

#include "node.h"
#include "geometry.h"

#include "classifier.h"

namespace keys
{
    const QString classifier = "classifier";
    const QString layer = "layer";
}

using namespace presentation;

namespace
{
    QPainterPath geometryToPath(const situation::GeometryPtr& geometry)
    {
        QPainterPath path;

        switch (geometry->type())
        {
        case situation::GeometryType::Point:
        case situation::GeometryType::MultiPoint:
            for (const auto& l2: geometry->points())
            {
                for (const auto& l1: l2)
                {
                    for (const QVector3D& vec: l1)
                    {
                        path.addEllipse(vec.toPointF(), 3, 3);
                    }
                }
            }
            break;
        case situation::GeometryType::Line:
        case situation::GeometryType::MultiLine:
            path.setFillRule(Qt::WindingFill);
            for (const auto& l2: geometry->points())
            {
                for (const auto& l1: l2)
                {
                    bool isStart = true;
                    for (const QVector3D& vec: l1)
                    {
                        if (isStart)
                        {
                            isStart = false;
                            path.moveTo(vec.toPointF());
                        }
                        else
                        {
                            path.lineTo(vec.toPointF());
                        }
                    }
                }
            }
            break;
        case situation::GeometryType::Polygon:
        case situation::GeometryType::MultiPolygon:
            for (const auto& l2: geometry->points())
            {
                for (const auto& l1: l2)
                {
                    QPolygonF polygon;
                    for (const QVector3D& vec: l1)
                    {
                        polygon.append(vec.toPointF());
                    }
                    path.addPolygon(polygon);
                }
            }
            break;
        default:
            break;
        }

        return path;
    }

    QList<QPainterPath> geometryToPathList(const situation::GeometryPtr& geometry)
    {
        QList<QPainterPath> list;

        list.append(geometryToPath(geometry));

        for (const situation::GeometryPtr& child: geometry->childGeometries())
        {
            list.append(geometryToPathList(child));
        }

        return list;
    }
}

class DrawObjectQPainter::DrawObjectQPainterPrivate
{
public:
    QList<QPainterPath> painterPaths;
    QString classifierId;
};

DrawObjectQPainter::DrawObjectQPainter():
    d(new DrawObjectQPainterPrivate())
{}

DrawObjectQPainter::DrawObjectQPainter(const DrawObjectQPainter& other):
    d(new DrawObjectQPainterPrivate(*other.d))
{}

DrawObjectQPainter::~DrawObjectQPainter()
{
    delete d;
}

DrawObjectQPainter DrawObjectQPainter::nodeToDrawObjectQPainter(
        const situation::NodePtr& node)
{
    DrawObjectQPainter object;

    object.d->classifierId = node->properties().value(
                                 keys::classifier).toString();

    if (node->geometry())
    {
        object.d->painterPaths = ::geometryToPathList(node->geometry());
    }

    return object;
}

DrawObjectQPainterMap DrawObjectQPainter::nodeToDrawObjectQPainterMap(
        const situation::NodePtr& node)
{
    if (node.isNull()) return DrawObjectQPainterMap();

    DrawObjectQPainterMap map;

    map.insert(node->properties().value(keys::layer, 0).toInt(),
               DrawObjectQPainter::nodeToDrawObjectQPainter(node));

    for(const situation::NodePtr& child: node->childNodes())
    {
        map.unite(
               DrawObjectQPainter::nodeToDrawObjectQPainterMap(child));
    }

    return map;
}

void DrawObjectQPainter::draw(QPainter* painter,
                    const classification::ClassifierPtrMap& classifierMap) const
{
    classification::ClassifierPtr classifier =
            classifierMap.value(d->classifierId);
    if (classifier)
    {
        painter->setPen(classifier->pen());
        painter->setBrush(classifier->brush());
    }

    for (const QPainterPath& path: d->painterPaths)
    {
        painter->drawPath(path);
    }
}
