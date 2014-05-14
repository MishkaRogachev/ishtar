#include "bounding_box.h"

using namespace situation;

BoundingBox::BoundingBox(qreal minX, qreal minY, qreal minZ,
                         qreal maxX, qreal maxY, qreal maxZ):
    m_min(minX, minY, minZ),
    m_max(maxX, maxY, maxZ)
{}

QVector3D BoundingBox::min() const
{
    return m_min;
}

QVector3D& BoundingBox::rMin()
{
    return m_min;
}

QVector3D BoundingBox::max() const
{
    return m_max;
}

QVector3D& BoundingBox::rMax()
{
    return m_max;
}

bool BoundingBox::isEqual(const BoundingBox& other) const
{
    return this->m_max == other.m_max && this->m_min == other.m_min;
}


