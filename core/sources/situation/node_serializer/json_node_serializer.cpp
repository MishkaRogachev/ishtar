#include "json_node_serializer.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

#include "node.h"

namespace keys
{
    const QString type = "type";
    const QString feature = "Feature";
    const QString featureCollection = "FeatureCollection";
    const QString id = "id";
    const QString gemetry = "gemetry";
    const QString gemetryType = "type";
    const QString point = "Point";
    const QString multiPoint = "MultiPoint";
    const QString line = "LineString";
    const QString multiLine = "MultiLineString";
    const QString polygone = "Polygone";
    const QString multiPolygone = "MultiPolygone";
    const QString geometryCollection = "GeometryCollection";
    const QString coordinates = "coordinates";
    const QString geometries = "geometries";
    const QString features = "features";
}

using namespace situation;

namespace // TODO: this should be refactored to geometryJsonParser
{

    QString geoJSonType(GeometryType type, const QVector3D2Vec& points)
    {
        switch (type)
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

    QJsonObject geometryToJSon(const GeometryPtr& geometry)
    {
        QJsonObject geometryJSon;

        QString gemetryType = geoJSonType(geometry->type(), geometry->points());

        if (!gemetryType.isEmpty())
        {
            geometryJSon.insert(keys::gemetryType, gemetryType);
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
                childGeometryJSon.append(geometryToJSon(childGeometry));
            }
            geometryJSon.insert(keys::geometries, childGeometryJSon);
        }

        return geometryJSon;
    }
}

JSonNodeSerializer::JSonNodeSerializer(bool isCompact):
    INodeSerializer(),
    isCompact(isCompact)
{}

QByteArray JSonNodeSerializer::toByteArray(const NodePtr& node) const
{
    QJsonDocument document(this->toJSonObject(node));
    return document.toJson( isCompact ?
                                QJsonDocument::Compact :
                                QJsonDocument::Indented);
}

NodePtr JSonNodeSerializer::fromByteArray(const QByteArray& array) const
{
    return this->fromJSonObject(QJsonDocument::fromJson(array).object());
}

QJsonObject JSonNodeSerializer::toJSonObject(const NodePtr& node) const
{
    if (node.isNull()) return QJsonObject();

    QJsonObject nodeJSon;

    nodeJSon.insert(keys::type, node->childNodes().isEmpty() ?
                        keys::feature :
                        keys::featureCollection);

    if (!node->id().isEmpty())
    {
        nodeJSon.insert(keys::id, node->id());
    }

    if (node->geometry())
    {
        nodeJSon.insert(keys::gemetry, ::geometryToJSon(node->geometry()));
    }

    //TODO: bbox

    if (!node->childNodes().isEmpty())
    {
        QJsonArray childNodeArrayJSon;

        for (const NodePtr& childNode: node->childNodes())
        {
            childNodeArrayJSon.append(this->toJSonObject(childNode));
        }

        nodeJSon.insert(keys::features, childNodeArrayJSon);
    }

    return nodeJSon;
}

NodePtr JSonNodeSerializer::fromJSonObject(const QJsonObject& object) const
{
    qDebug() << object;

    NodePtr node(new Node());
    node->setId(object.value(keys::id).toString());

    return node;
}
