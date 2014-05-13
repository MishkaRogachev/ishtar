#ifndef SITUATION_NODE_H
#define SITUATION_NODE_H

#include "point.hpp"
#include "excodes.h"

namespace situation
{
    class Node
    {
    public:
        Node(Excode excode = Excode::Default,
             const common::PointPtrList& points = common::PointPtrList());
        virtual ~Node();

        void setExcode(Excode excode);
        Excode excode() const;

        common::PointPtrList points() const;
        common::PointPtrList& rPoints() const;

    private:
        class NodePrivate;
        NodePrivate* d;

        Node(const Node& other) = delete;
        Node& operator =(const Node& other) = delete;
    };
}

#endif // SITUATION_NODE_H
