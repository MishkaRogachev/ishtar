#include "situation_node_drawer_qpainter.h"

#include <QPainter>
#include <QMatrix>

#include "node.h"
#include "geometry.h"

namespace presentation
{
    class DrawObject
    {
    public:
        QList<QPainterPath> painterPaths;
        QPen pen = QPen(Qt::darkGray, 0);
        QBrush brush = QBrush(Qt::gray, Qt::SolidPattern);

        void draw(QPainter* painter) const
        {
            painter->setPen(pen);
            painter->setBrush(brush);

            for (const QPainterPath& path: painterPaths)
            {
                painter->drawPath(path);
            }
        }
    };

    typedef QMap<QString, DrawObject > DrawMap;

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

    DrawObject nodeToDrawObject(const situation::NodePtr& node)
    {
        DrawObject object;

        //object.classifierId = node->properties().value(keys::classifier).toString();
        object.pen.setCosmetic(true);

        if (node->geometry())
        {
            object.painterPaths = geometryToPathList(node->geometry());
        }

        return object;
    }

    DrawMap nodeToDrawMap(const situation::NodePtr& node)
    {
        if (node.isNull()) return DrawMap();

        DrawMap map;

        map.insert(node->id(), nodeToDrawObject(node));

        for(const situation::NodePtr& child: node->childNodes())
        {
            map.unite(nodeToDrawMap(child));
        }

        return map;
    }
}

using namespace presentation;

class SituationNodeDrawerQPainter::SituationNodeDrawerQPainterPrivate
{
public:
    DrawMap drawMap;
};

SituationNodeDrawerQPainter::SituationNodeDrawerQPainter():
    ISituationNodeDrawer(),
    d(new SituationNodeDrawerQPainterPrivate())
{}

SituationNodeDrawerQPainter::~SituationNodeDrawerQPainter()
{
    delete d;
}

void SituationNodeDrawerQPainter::setNode(const situation::NodePtr& node)
{
    d->drawMap = nodeToDrawMap(node);
}

void SituationNodeDrawerQPainter::draw(QPainter* painter,
                                       const QMatrix& trasformationMatrix)
{
    painter->save();
    painter->setTransform(QTransform(trasformationMatrix));

    for (const DrawObject& object: d->drawMap)
    {
        object.draw(painter);
    }

    painter->restore();
}
