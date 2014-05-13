#ifndef POINT_HPP
#define POINT_HPP

#include <QSharedPointer>
#include <QList>

namespace common
{
    class Point
    {
    public:

        double latitude() const
        {
            return m_latitude;
        }

        void setLatitude(double latitude)
        {
            m_latitude = latitude;
        }

        double longitude() const
        {
            return m_longitude;
        }

        void setLongitude(double longitude)
        {
            m_longitude = longitude;
        }

        double altitude() const
        {
            return m_altitude;
        }

        void setAltitude(double altitude)
        {
            m_altitude = altitude;
        }

    private:
        double m_latitude;
        double m_longitude;
        double m_altitude;
    };

    typedef QSharedPointer<Point> PointPtr;
    typedef QList<PointPtr> PointPtrList;
}

#endif //POINT_HPP



