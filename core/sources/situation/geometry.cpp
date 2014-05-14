#include "geometry.h"

using namespace situation;

Geometry::Geometry():
    m_type(GeometryType::Point)
{}

GeometryType Geometry::type() const
{
    return m_type;
}

void Geometry::setType(GeometryType type)
{
    m_type = type;
}

GeometryPtrList Geometry::childGeometries() const
{
    return m_childGeometries;
}

GeometryPtrList& Geometry::rChildGeometries()
{
    return m_childGeometries;
}

QVector3D2Vec Geometry::points() const
{
    return m_points;
}

QVector3D2Vec& Geometry::rPoints()
{
    return m_points;
}



