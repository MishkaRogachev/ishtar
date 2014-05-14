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

QJsonObject JSonNodeSerializer::toJSonObject(const NodePtr& node) const
{
    // TODO:
    return QJsonObject();
}
