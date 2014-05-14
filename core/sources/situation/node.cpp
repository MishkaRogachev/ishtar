#include "node.h"

#include "bounding_box.h"
#include "geometry.h"

using namespace situation;

Node::Node(const QString& id,
           const GeometryPtr& geometry,
           const BoundingBoxPtr& boundingBox,
           const QVariantMap& properties,
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

QVariantMap Node::properties() const
{
    return m_properties;
}

void Node::setProperties(const QVariantMap& properties)
{
    m_properties = properties;
}

NodePtrList Node::childNodes() const
{
    return m_childNodes;
}

void Node::setChildNodes(const NodePtrList& childNodes)
{
    m_childNodes = childNodes;
}

bool Node::isEqual(const Node& other) const
{
    if (m_id != other.m_id) return false;

    if (m_geometry.isNull() || other.m_geometry.isNull())
    {
        if (m_geometry != other.m_geometry) return false;
    }
    else
    {
        if (m_geometry != other.m_geometry &&
            !m_geometry->isEqual(*other.m_geometry)) return false;
    }

    if (m_boundingBox.isNull() || other.m_boundingBox.isNull())
    {
        if (m_boundingBox != other.m_boundingBox) return false;
    }
    else
    {   if (m_boundingBox != other.m_boundingBox &&
            !m_boundingBox->isEqual(*other.m_boundingBox)) return false;
    }

    if (m_properties != other.m_properties) return false;

    if (m_childNodes.count() != other.m_childNodes.count()) return false;

    for (int i = 0; i < m_childNodes.count(); ++i)
    {
        if (!m_childNodes.at(i)->isEqual(*other.m_childNodes.at(i))) return false;
    }

    return true;
}


