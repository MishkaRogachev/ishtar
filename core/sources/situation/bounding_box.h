#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <QVector3D>

namespace situation
{
    class BoundingBox
    {
    public:
        BoundingBox(qreal minX = 0.0d, qreal minY = 0.0d, qreal minZ = 0.0d,
                    qreal maxX = 0.0d, qreal maxY = 0.0d, qreal maxZ = 0.0d);

        QVector3D min() const;
        QVector3D& rMin();

        QVector3D max() const;
        QVector3D& rMax();

        bool isEqual(const BoundingBox& other) const;
        inline friend bool operator==(const BoundingBox& left, const BoundingBox& right)
        {
            return left.isEqual(right);
        }

    private:
        QVector3D m_min;
        QVector3D m_max;
    };
}

#endif // BOUNDING_BOX_H
