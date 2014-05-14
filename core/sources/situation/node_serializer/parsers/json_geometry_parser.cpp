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

namespace
{
    QJsonArray pointsToJSonArray(const QVector< QVector3D > points)
    {
        QJsonArray arrayJSon;

        for (const QVector3D& point: points)
        {
            QJsonArray pointArray;

            pointArray.append(point.x());
            pointArray.append(point.y());
            pointArray.append(point.z());

            arrayJSon.append(pointArray);
        }

        return arrayJSon;
    }

    QVector< QVector3D > jSonArrayToPoints(const QJsonArray& arrayJSon)
    {
        QVector< QVector3D > points;

        for (const QJsonValue& value: arrayJSon)
        {
            QJsonArray array = value.toArray();

            if (array.count() < 3) continue;

            QVector3D point;

            point.setX(array.first().toDouble());
            point.setY(array.at(1).toDouble());
            point.setZ(array.at(2).toDouble());

            points.append(point);
        }

        return points;
    }
}

using namespace situation;

QJsonObject JSonGeometryParser::parseGeometry(const GeometryPtr& geometry)
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
                arrayJSon.append(::pointsToJSonArray(array));
            }
        }
        else
        {
            arrayJSon.append(pointsToJSonArray(geometry->points().first()));
        }

        geometryJSon.insert(keys::coordinates, arrayJSon);
    }

    if (!geometry->childGeometries().isEmpty())
    {
        QJsonArray childGeometryJSon;

        for (const GeometryPtr& childGeometry: geometry->childGeometries())
        {
            childGeometryJSon.append(JSonGeometryParser::parseGeometry(childGeometry));
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

GeometryPtr JSonGeometryParser::parseJson(const QJsonObject& object)
{
    if (object.isEmpty()) return GeometryPtr();

    GeometryPtr geometry(new Geometry());

    const QString& type = object.value(keys::geometryType).toString();

    if (type == keys::point ||
        type == keys::multiPoint)
    {
        geometry->setType(GeometryType::Point);
    }
    else
    if (type == keys::line ||
        type == keys::multiLine)
    {
        geometry->setType(GeometryType::Line);
    }
    else
    if (type == keys::polygone ||
        type == keys::multiPolygone)
    {
        geometry->setType(GeometryType::Polygone);
    }
    else
    if (type == keys::geometryCollection)
    {
        geometry->setType(GeometryType::Collection);
    }

    const QJsonArray& coordinatesArray = object.value(keys::coordinates).toArray();

    if (!coordinatesArray.isEmpty())
    {
        //TODO: wrong
        QVector3D2Vec points;

        for (const QJsonValue& pointsValue: coordinatesArray)
        {
            points.append(::jSonArrayToPoints(pointsValue.toArray()));
        }

        geometry->setPoints(points);
    }

//    if (!geometry->points().isEmpty())
//    {
//        QJsonArray arrayJSon;

//        if (geometry->points().count() > 1)
//        {
//            for (const auto& array: geometry->points())
//            {
//                arrayJSon.append(::pointsToJSonArray(array));
//            }
//        }
//        else
//        {
//            arrayJSon.append(pointsToJSonArray(geometry->points().first()));
//        }

//        geometryJSon.insert(keys::coordinates, arrayJSon);
//    }

//    if (!geometry->childGeometries().isEmpty())
//    {
//        QJsonArray childGeometryJSon;

//        for (const GeometryPtr& childGeometry: geometry->childGeometries())
//        {
//            childGeometryJSon.append(JSonGeometryParser::parseGeometry(childGeometry));
//        }
//        geometryJSon.insert(keys::geometries, childGeometryJSon);
//    }

    return geometry;
}
