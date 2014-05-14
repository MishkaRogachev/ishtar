#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>

namespace situation
{
    class Node;

    typedef QSharedPointer<Node> NodePtr;

    typedef QList<NodePtr> NodePtrList;
}

#endif // SITUATION_TRAITS_H
