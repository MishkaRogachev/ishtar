#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>

namespace situation
{
    class Node;
    class Layer;
    class Map;

    typedef QSharedPointer<Node> NodePtr;
    typedef QSharedPointer<Layer> LayerPtr;
    typedef QSharedPointer<Map> MapPtr;

    typedef QList<NodePtr> NodePtrList;
    typedef QList<LayerPtr> LayerPtrList;
    typedef QList<MapPtr> MapPtrList;
}

#endif // SITUATION_TRAITS_H
