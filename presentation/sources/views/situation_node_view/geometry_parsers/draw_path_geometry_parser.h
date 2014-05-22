#ifndef DRAW_PATH_GEOMETRY_PARSER_H
#define DRAW_PATH_GEOMETRY_PARSER_H

#include <QMap>
#include <QPainterPath>
#include <QPen>
#include <QBrush>

#include "situation_traits.h"
#include "classification_traits.h"

namespace presentation
{
    struct PaintedNodeDrawObject
    {
        QList<QPainterPath> painterPaths;
        QPen pen = QPen(Qt::darkGray, 0);
        QBrush brush = QBrush(Qt::gray, Qt::SolidPattern);

        void draw(QPainter* painter) const;
    };

    typedef QMap<QString, PaintedNodeDrawObject > PaintedNodeDrawMap;

    class DrawPathGeometryParser
    {
    public:
        QPainterPath geometryToDrawPath(const situation::GeometryPtr& geometry);
        QList<QPainterPath> geometryToDrawPathList(
                const situation::GeometryPtr& geometry);
        PaintedNodeDrawObject nodeToDrawObject(const situation::NodePtr& node,
                const classification::ClassifierPtr& classifier);
        PaintedNodeDrawMap generateDrawMap(
                const situation::NodePtr& node,
                const classification::ClassifierPtr& classifier);
    };
}

#endif // DRAW_PATH_GEOMETRY_PARSER_H
