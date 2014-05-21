#include "draw_path_geometry_parser.h"

#include <QDebug>
#include <QPainter>

#include "node.h"
#include "geometry.h"

namespace keys
{
    const QString pen = "pen";
    const QString brush = "brush";
}

using namespace presentation;

QPainterPath DrawPathGeometryParser::geometryToDrawPath(
        const situation::GeometryPtr& geometry)
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

QList<QPainterPath> DrawPathGeometryParser::geometryToDrawPathList(
        const situation::GeometryPtr& geometry)
{
    QList<QPainterPath> list;

    list.append(this->geometryToDrawPath(geometry));

    for (const situation::GeometryPtr& child: geometry->childGeometries())
    {
        list.append(this->geometryToDrawPathList(child));
    }

    return list;
}

NodeDrawObject DrawPathGeometryParser::nodeToDrawObject(const situation::NodePtr& node)
{
    NodeDrawObject object;

    if (node->properties().contains(keys::pen))
    {
        object.pen = node->properties().value(keys::pen).value<QPen>();
    }
    object.pen.setCosmetic(true);

    if (node->properties().contains(keys::brush))
    {
        object.brush = node->properties().value(keys::brush).value<QBrush>();
    }

    if (node->geometry())
    {
        object.painterPaths = this->geometryToDrawPathList(node->geometry());
    }

    return object;
}

NodeDrawMap DrawPathGeometryParser::generateDrawMap(const situation::NodePtr& node)
{
    if (node.isNull()) return NodeDrawMap();

    NodeDrawMap map;

    map.insert(node->id(), this->nodeToDrawObject(node));

    for(const situation::NodePtr& child: node->childNodes())
    {
        map.unite(this->generateDrawMap(child));
    }

    return map;
}

void NodeDrawObject::draw(QPainter* painter) const
{
    painter->setPen(pen);
    painter->pen();
    painter->setBrush(brush);

    for (const QPainterPath& path: painterPaths)
    {
        painter->drawPath(path);
    }
}
