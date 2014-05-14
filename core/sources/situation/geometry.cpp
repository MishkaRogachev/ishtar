#include "geometry.h"

using namespace situation;

Geometry::Geometry(GeometryType type, const QVector3D2Vec& points):
    m_type(type),
    m_points(points)
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

void Geometry::setPoints(const QVector3D2Vec& points)
{
    m_points = points;
}
