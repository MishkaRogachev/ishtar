#ifndef DRAW_PATH_GEOMETRY_PARSER_H
#define DRAW_PATH_GEOMETRY_PARSER_H

#include <QMap>
#include <QPainterPath>
#include <QPen>
#include <QBrush>

#include "situation_traits.h"

namespace presentation
{
    struct NodeDrawObject
    {
        QList<QPainterPath> painterPaths;
        QPen pen;
        QBrush brush;

        void draw(QPainter* painter) const;
    };

    typedef QMap<QString, NodeDrawObject > NodeDrawMap;

    class DrawPathGeometryParser
    {
    public:
        QPainterPath geometryToDrawPath(const situation::GeometryPtr& geometry);
        QList<QPainterPath> geometryToDrawPathList(const situation::GeometryPtr& geometry);
        NodeDrawObject nodeToDrawObject(const situation::NodePtr& node);
        NodeDrawMap generateDrawMap(const situation::NodePtr& node);
    };
}

#endif // DRAW_PATH_GEOMETRY_PARSER_H
