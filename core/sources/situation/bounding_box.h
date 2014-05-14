#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <QVector3D>

namespace situation
{
    class BoundingBox
    {
    public:
        BoundingBox();

        QVector3D min() const;
        QVector3D& rMin();

        QVector3D max() const;
        QVector3D& rMax();

    private:
        QVector3D m_min;
        QVector3D m_max;
    };
}

#endif // BOUNDING_BOX_H
