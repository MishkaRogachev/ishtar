#include "json_node_serializer.h"

#include <QJsonDocument>
#include <QDebug>

#include "node.h"

namespace keys
{
    const QString id = "id";
}

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
    if (node.isNull()) return QJsonObject();

    QJsonObject json;

    if (!node->id().isEmpty()) json.insert(keys::id, node->id());
    return json;
}

NodePtr JSonNodeSerializer::fromJSonObject(const QJsonObject& object) const
{
//    qDebug() << object;

    NodePtr node(new Node());
    node->setId(object.value(keys::id).toString());

    return node;
}
