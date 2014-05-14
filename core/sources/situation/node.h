#ifndef SITUATION_NODE_H
#define SITUATION_NODE_H

#include "situation_traits.h"

#include "bounding_box.h"
#include "geometry.h"

namespace situation
{
    class Node
    {
    public:
        Node();
        virtual ~Node();

        Geometry geometry() const;
        Geometry& rGeometry();

        BoundingBox boundingBox() const;
        BoundingBox& rBoundingBox();

        NodePtrList childNodes() const;
        NodePtrList& rChildNodes();

    private:
        Geometry m_geometry;
        BoundingBox m_boundingBox;
        NodePtrList m_childNodes;
    };
}

#endif // SITUATION_NODE_H
