#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>
#include <QVector>

namespace situation
{
    class Point;
    class Geometry;
    class Node;

    typedef QVector< QVector< Point > > Point2Vec;

    typedef QSharedPointer<Geometry> GeometryPtr;
    typedef QSharedPointer<Node> NodePtr;

    typedef QList<GeometryPtr> GeometryPtrList;
    typedef QList<NodePtr> NodePtrList;
}

#endif // SITUATION_TRAITS_H
