#include "node.h"

using namespace situation;

Node::Node()
{}

Node::~Node()
{}

Geometry Node::geometry() const
{
    return m_geometry;
}

Geometry& Node::rGeometry()
{
    return m_geometry;
}

BoundingBox Node::boundingBox() const
{
    return m_boundingBox;
}

BoundingBox& Node::rBoundingBox()
{
    return m_boundingBox;
}

NodePtrList Node::childNodes() const
{
    return m_childNodes;
}

NodePtrList& Node::rChildNodes()
{
    return m_childNodes;
}


