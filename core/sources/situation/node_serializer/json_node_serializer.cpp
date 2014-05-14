#include "json_node_serializer.h"

#include <QJsonDocument>

using namespace situation;

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
    // TODO:
    return QJsonObject();
}

NodePtr JSonNodeSerializer::fromJSonObject(const QJsonObject& object) const
{
    //TODO:
    return NodePtr();
}
