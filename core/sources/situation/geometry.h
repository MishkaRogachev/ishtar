#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "situation_traits.h"

namespace situation
{
    enum class GeometryType
    {
        Point,
        Line,
        Polygone,
        Collection
    };

    class Geometry
    {
    public:
        Geometry(GeometryType type = GeometryType::Point,
                 const QVector3D2Vec& points = QVector3D2Vec());

        GeometryType type() const;
        void setType(GeometryType type);

        GeometryPtrList childGeometries() const;
        GeometryPtrList& rChildGeometries();

        QVector3D2Vec points() const;
        void setPoints(const QVector3D2Vec& points);

        bool isEqual(const Geometry& other) const;
        inline friend bool operator==(const Geometry& left, const Geometry& right)
        {
            return left.isEqual(right);
        }

    private:
        GeometryType m_type;
        QVector3D2Vec m_points;
        GeometryPtrList m_childGeometries;
    };
}
#endif // GEOMETRY_H
