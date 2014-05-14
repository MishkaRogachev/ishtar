#include "json_node_serializer.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

#include "node.h"
#include "bounding_box.h"

#include "parsers/json_geometry_parser.h"

namespace keys
{
    const QString type = "type";
    const QString feature = "Feature";
    const QString featureCollection = "FeatureCollection";
    const QString id = "id";
    const QString bBox = "bbox";
    const QString geometry = "geometry";
    const QString features = "features";
}

using namespace situation;

JSonNodeSerializer::JSonNodeSerializer(JSonSerializationType type):
    INodeSerializer(),
    type(type)
{}

QByteArray JSonNodeSerializer::toByteArray(const NodePtr& node) const
{
    QJsonDocument document(this->toJSonObject(node));

    switch (type)
    {
    case JSonSerializationType::CompactText:
        return document.toJson(QJsonDocument::Compact);
    case JSonSerializationType::IndentedText:
        return document.toJson(QJsonDocument::Indented);
    case JSonSerializationType::Binary:
        return document.toBinaryData();
    }
    return QByteArray();
}

NodePtr JSonNodeSerializer::fromByteArray(const QByteArray& array) const
{
    return this->fromJSonObject((type == JSonSerializationType::Binary ?
                                    QJsonDocument::fromBinaryData(array) :
                                    QJsonDocument::fromJson(array)).object());
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
        nodeJSon.insert(keys::geometry,
                        JSonGeometryParser::parseGeometry(node->geometry()));
    }

    if (node->boundingBox())
    {
        QJsonArray bBoxJSon;

        bBoxJSon.append(node->boundingBox()->min().x());
        bBoxJSon.append(node->boundingBox()->min().y());
        bBoxJSon.append(node->boundingBox()->min().z());

        bBoxJSon.append(node->boundingBox()->max().x());
        bBoxJSon.append(node->boundingBox()->max().y());
        bBoxJSon.append(node->boundingBox()->max().z());

        nodeJSon.insert(keys::bBox, bBoxJSon);
    }

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
    NodePtr node(new Node());
    node->setId(object.value(keys::id).toString());

    node->setGeometry(JSonGeometryParser::parseJson(
                          object.value(keys::geometry).toObject()));

    return node;
}
