#include "bounding_box.h"

using namespace situation;

BoundingBox::BoundingBox()
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

