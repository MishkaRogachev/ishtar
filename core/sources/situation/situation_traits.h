#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <QVector3D>

namespace situation
{
    class Point;
    class Geometry;
    class BoundingBox;
    class Node;

    typedef QVector< QVector< QVector < QVector3D > > > QVector3D3Vec;

    typedef QSharedPointer<Geometry> GeometryPtr;
    typedef QSharedPointer<BoundingBox> BoundingBoxPtr;
    typedef QSharedPointer<Node> NodePtr;

    typedef QList<GeometryPtr> GeometryPtrList;
    typedef QList<NodePtr> NodePtrList;
}

#endif // SITUATION_TRAITS_H
