#include "json_geometry_parser.h"

#include <QJsonArray>
#include <QMap>

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

            if (array.count() < 2) continue;

            QVector3D point;

            point.setX(array.first().toDouble());
            point.setY(array.at(1).toDouble());

            if (array.count() > 2) point.setZ(array.at(2).toDouble());

            points.append(point);
        }

        return points;
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
        //TODO:
            return QVector3D3Vec();
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
