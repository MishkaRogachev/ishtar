#include "json_geometry_parser.h"

#include <QJsonArray>

#include "geometry.h"

namespace keys
{
    const QString geometryType = "type";
    const QString point = "Point";
    const QString multiPoint = "MultiPoint";
    const QString line = "LineString";
    const QString multiLine = "MultiLineString";
    const QString polygone = "Polygone";
    const QString multiPolygone = "MultiPolygone";
    const QString geometryCollection = "GeometryCollection";
    const QString coordinates = "coordinates";
    const QString geometries = "geometries";
}

using namespace situation;

QJsonObject JSonGeometryParser::parse(const GeometryPtr& geometry)
{
    QJsonObject geometryJSon;

    QString geometryType = JSonGeometryParser::geometryTypeString(geometry);

    if (!geometryType.isEmpty())
    {
        geometryJSon.insert(keys::geometryType, geometryType);
    }

    if (!geometry->points().isEmpty())
    {
        QJsonArray arrayJSon;

        if (geometry->points().count() > 1)
        {
            for (const auto& array: geometry->points())
            {
                QJsonArray pointsArrayJSon;

                for (const QVector3D& point: array)
                {
                    pointsArrayJSon.append(point.x());
                    pointsArrayJSon.append(point.y());
                    pointsArrayJSon.append(point.z());
                }

                arrayJSon.append(pointsArrayJSon);
            }
        }
        else
        {
            for (const QVector3D& point: geometry->points().first())
            {
                arrayJSon.append(point.x());
                arrayJSon.append(point.y());
                arrayJSon.append(point.z());
            }
        }

        geometryJSon.insert(keys::coordinates, arrayJSon);
    }

    if (!geometry->childGeometries().isEmpty())
    {
        QJsonArray childGeometryJSon;

        for (const GeometryPtr& childGeometry: geometry->childGeometries())
        {
            childGeometryJSon.append(JSonGeometryParser::parse(childGeometry));
        }
        geometryJSon.insert(keys::geometries, childGeometryJSon);
    }

    return geometryJSon;
}

QString JSonGeometryParser::geometryTypeString(const GeometryPtr& geometry)
{
    const QVector3D2Vec& points = geometry->points();

    switch (geometry->type())
    {
    case GeometryType::Point:
        if (points.isEmpty() ||
            points.count() > 1 ||
            points.first().isEmpty()) return QString();
        if (points.first().count() == 1) return keys::point;
        else return keys::multiPoint;

    case GeometryType::Line:
        if (points.isEmpty()) return QString();

        if (points.count() == 1)
        {
            if (points.first().count() < 2) return QString();
            return keys::line;
        }

        for (const auto& array: points)
        {
            if (array.count() < 2) return QString();
        }
        return keys::multiLine;

    case GeometryType::Polygone:
        if (points.isEmpty()) return QString();

        if (points.count() == 1)
        {
            if (points.first().count() < 3) return QString();
            return keys::polygone;
        }

        for (const auto& array: points)
        {
            if (array.count() < 3) return QString();
        }
        return keys::multiPolygone;

    case GeometryType::Collection:
        return keys::geometryCollection;
    }
    return QString();
}
