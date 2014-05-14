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

void Node::setGeometry(const Geometry& geometry)
{
    m_geometry = geometry;
}

BoundingBox Node::boundingBox() const
{
    return m_boundingBox;
}

void Node::setBoundingBox(const BoundingBox& boundingBox)
{
    m_boundingBox = boundingBox;
}

NodePtrList Node::childrenNodes() const
{
    return m_childrenNodes;
}

NodePtrList& Node::rChildrenNodes()
{
    return m_childrenNodes;
}


