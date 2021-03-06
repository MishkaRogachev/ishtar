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
    const QString geometry = "geometry";
    const QString bBox = "bbox";
    const QString features = "features";
    const QString properties = "properties";
}

using namespace situation;

JSonNodeSerializer::JSonNodeSerializer(JSonSerializationType type):
    INodeSerializer(),
    type(type)
{}

QByteArray JSonNodeSerializer::nodeToByteArray(const NodePtr& node) const
{
    QJsonDocument document(this->nodeToJSonObject(node));

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

NodePtr JSonNodeSerializer::byteArrayToNode(const QByteArray& array) const
{
    return this->jSonObjectToNode((type == JSonSerializationType::Binary ?
                                    QJsonDocument::fromBinaryData(array) :
                                    QJsonDocument::fromJson(array)).object());
}

QJsonObject JSonNodeSerializer::nodeToJSonObject(const NodePtr& node) const
{
    if (node.isNull()) return QJsonObject();

    QJsonObject nodeJSon;

    if (!node->id().isEmpty())
    {
        nodeJSon.insert(keys::id, node->id());
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

    if (!node->properties().isEmpty())
    {
        nodeJSon.insert(keys::properties,
                        QJsonValue::fromVariant(QVariant(node->properties())));
    }

    if (node->geometry())
    {
        nodeJSon.insert(keys::geometry,
                        JSonGeometryParser::toJSon(node->geometry()));
    }

    if (!node->childNodes().isEmpty())
    {
        nodeJSon.insert(keys::type, keys::featureCollection);

        QJsonArray childNodeArrayJSon;

        for (const NodePtr& childNode: node->childNodes())
        {
            childNodeArrayJSon.append(this->nodeToJSonObject(childNode));
        }

        nodeJSon.insert(keys::features, childNodeArrayJSon);
    }
    else
    {
        nodeJSon.insert(keys::type, keys::feature);
    }

    return nodeJSon;
}

NodePtr JSonNodeSerializer::jSonObjectToNode(const QJsonObject& object) const
{
    NodePtr node(new Node());

    node->setId(object.value(keys::id).toString());

    const QJsonArray& bBoxArray = object.value(keys::bBox).toArray();
    if (bBoxArray.count() == 6)
    {
        node->setBoundingBox(BoundingBoxPtr(
                                 new BoundingBox(bBoxArray.at(0).toDouble(),
                                                 bBoxArray.at(1).toDouble(),
                                                 bBoxArray.at(2).toDouble(),
                                                 bBoxArray.at(3).toDouble(),
                                                 bBoxArray.at(4).toDouble(),
                                                 bBoxArray.at(5).toDouble())));
    }

    node->setProperties(object.value(keys::properties).toVariant().toMap());

    const QJsonObject& geometryObject = object.value(keys::geometry).toObject();
    if (!geometryObject.isEmpty())
    {
        node->setGeometry(JSonGeometryParser::toGeometry(geometryObject));
    }

    const QJsonArray& childArray =
            object.value(keys::features).toArray();

    if (!childArray.isEmpty())
    {
        NodePtrList childList;
        for(const QJsonValue& child: childArray)
        {
            childList.append(this->jSonObjectToNode(child.toObject()));
        }
        node->setChildNodes(childList);
    }

    return node;
}
