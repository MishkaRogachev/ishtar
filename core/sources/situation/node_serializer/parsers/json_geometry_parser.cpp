#include "json_geometry_parser.h"

#include <QJsonArray>
#include <QMap>
#include <QDebug>

#include "geometry.h"

using namespace situation;

namespace keys
{
    const QString geometryType = "type";
    const QString coordinates = "coordinates";
    const QString geometries = "geometries";

    const QMap<GeometryType, QString> typeMap(
    {
                { GeometryType::Point, "Point" },
                { GeometryType::Line, "LineString" },
                { GeometryType::Polygon, "Polygon" },
                { GeometryType::MultiPoint, "MultiPoint" },
                { GeometryType::MultiLine, "MultiLineString" },
                { GeometryType::MultiPolygon, "MultiPolygon" },
                { GeometryType::Collection, "GeometryCollection" }
            });
}

namespace
{
//    QJsonArray pointsToJSonArray(const QVector< QVector3D > points)
//    {
//        QJsonArray arrayJSon;

//        for (const QVector3D& point: points)
//        {
//            QJsonArray pointArray;

//            pointArray.append(point.x());
//            pointArray.append(point.y());
//            pointArray.append(point.z());

//            arrayJSon.append(pointArray);
//        }

//        return arrayJSon;
//    }

    QVector3D jSonArrayToPoints(const QJsonArray& arrayJSon)
    {
        if (arrayJSon.count() < 2) return QVector3D();

        QVector3D point;

        point.setX(arrayJSon.first().toDouble());
        point.setY(arrayJSon.at(1).toDouble());
        if (arrayJSon.count() > 2) point.setZ(arrayJSon.at(2).toDouble());

        return point;
    }


    QJsonArray pointsToJSonArray(const QVector3D3Vec points,
                                 GeometryType type)
    {
    //TODO:
        return QJsonArray();
    }

    QVector3D3Vec jSonArrayToPoints(const QJsonArray& arrayJSon,
                                    GeometryType type)
    {
        QVector3D3Vec points;

        QVector< QVector < QVector3D > > l1Array;
        QVector < QVector3D >l2Array;

        switch (type) {
        case GeometryType::Point:
            l2Array.append(jSonArrayToPoints(arrayJSon));
            l1Array.append(l2Array);
            points.append(l1Array);
            break;
        case GeometryType::Line:
            for (const QJsonValue& l2Value: arrayJSon)
            {
                l2Array.append(jSonArrayToPoints(l2Value.toArray()));
            }
            l1Array.append(l2Array);
            points.append(l1Array);
            break;
        }

        return points;
    }
}

QJsonObject JSonGeometryParser::toJSon(const GeometryPtr& geometry)
{
    QJsonObject geometryJSon;

    geometryJSon.insert(keys::geometryType, keys::typeMap.value(geometry->type()));

    if (!geometry->points().isEmpty())
    {
        geometryJSon.insert(keys::coordinates,
                            ::pointsToJSonArray(geometry->points(), geometry->type()));
    }

    if (!geometry->childGeometries().isEmpty())
    {
        QJsonArray childGeometryJSon;

        for (const GeometryPtr& childGeometry: geometry->childGeometries())
        {
            childGeometryJSon.append(JSonGeometryParser::toJSon(childGeometry));
        }
        geometryJSon.insert(keys::geometries, childGeometryJSon);
    }

    return geometryJSon;
}

GeometryPtr JSonGeometryParser::toGeometry(const QJsonObject& object)
{
    if (object.isEmpty()) return GeometryPtr();

    GeometryPtr geometry(new Geometry());

    geometry->setType(keys::typeMap.key(
                          object.value(keys::geometryType).toString()));

    const QJsonArray& coordinatesArray =
            object.value(keys::coordinates).toArray();
    if (!coordinatesArray.isEmpty())
    {
        geometry->setPoints(::jSonArrayToPoints(coordinatesArray,
                                                geometry->type()));
    }

    const QJsonArray& geometriesArray =
            object.value(keys::geometries).toArray();
    if (!geometriesArray.isEmpty())
    {
        GeometryPtrList geometries;
        for (const QJsonValue& geometryValue: geometriesArray)
        {
            geometries.append(JSonGeometryParser::
                              toGeometry(geometryValue.toObject()));
        }
        geometry->setChildGeometries(geometries);
    }

    return geometry;
}
