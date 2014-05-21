#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "situation_traits.h"

namespace situation
{
    enum class GeometryType
    {
        Point,
        Line,
        Polygon,
        MultiPoint,
        MultiLine,
        MultiPolygon,
        Collection
    };

    // TODO: propetries
    class Geometry
    {
    public:
        Geometry(GeometryType type = GeometryType::Point,
                 const QVector3D3Vec& points = QVector3D3Vec());

        GeometryType type() const;
        void setType(GeometryType type);

        GeometryPtrList childGeometries() const;
        GeometryPtrList& rChildGeometries();
        void setChildGeometries(const GeometryPtrList& childGeometries);

        QVector3D3Vec points() const;
        void setPoints(const QVector3D3Vec& points);

        bool isEqual(const Geometry& other) const;
        inline friend bool operator==(const Geometry& left, const Geometry& right)
        {
            return left.isEqual(right);
        }
        inline friend bool operator!=(const Geometry& left, const Geometry& right)
        {
            return !left.isEqual(right);
        }

    private:
        GeometryType m_type;
        QVector3D3Vec m_points;
        GeometryPtrList m_childGeometries;
    };
}
#endif // GEOMETRY_H
