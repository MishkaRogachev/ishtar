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

bool Geometry::isEqual(const Geometry& other) const
{
    for (int i = 0; i < m_points.count(); ++i)
    {
        if (other.m_points.count() <= i) return false;

        for (int j = 0; j < m_points.at(i).count(); ++j)
        {
            if (other.m_points.at(i).count() <= j) return false;

            if (m_points.at(i).at(j) != other.m_points.at(i).at(j)) return false;
        }
    }

    return true;
}

