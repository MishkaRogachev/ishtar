#include "node.h"

using namespace situation;


Node::Node(const QString& id,
           const GeometryPtr& geometry,
           const BoundingBoxPtr& boundingBox,
           const QVariant& properties,
           const NodePtrList& childNodes):
    m_id(id),
    m_geometry(geometry),
    m_boundingBox(boundingBox),
    m_properties(properties),
    m_childNodes(childNodes)
{}

QString Node::id() const
{
    return m_id;
}

void Node::setId(const QString& id)
{
    m_id = id;
}

GeometryPtr Node::geometry() const
{
    return m_geometry;
}

void Node::setGeometry(const GeometryPtr& geometry)
{
    m_geometry = geometry;
}

BoundingBoxPtr Node::boundingBox() const
{
    return m_boundingBox;
}

void Node::setBoundingBox(const BoundingBoxPtr& boundingBox)
{
    m_boundingBox = boundingBox;
}

QVariant Node::properties() const
{
    return m_properties;
}

QVariant& Node::rProperties()
{
    return m_properties;
}

NodePtrList Node::childNodes() const
{
    return m_childNodes;
}

NodePtrList& Node::rChildNodes()
{
    return m_childNodes;
}


