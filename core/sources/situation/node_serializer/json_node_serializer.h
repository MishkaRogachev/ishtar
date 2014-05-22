#ifndef JSON_NODE_SERIALISER_H
#define JSON_NODE_SERIALISER_H

#include "i_node_serializer.h"

#include <QJsonObject>

namespace situation
{
    enum class JSonSerializationType
    {
        CompactText,
        IndentedText,
        Binary
    };

    class JSonNodeSerializer : public INodeSerializer
    {
    public:
        JSonNodeSerializer(JSonSerializationType type =
                JSonSerializationType::IndentedText);

        virtual QByteArray nodeToByteArray(const NodePtr& node) const override;
        virtual NodePtr byteArrayToNode(const QByteArray& array) const override;

        QJsonObject nodeToJSonObject(const NodePtr& node) const;
        NodePtr jSonObjectToNode(const QJsonObject& object) const;

    private:
        JSonSerializationType type;
    };
}
#endif // JSON_NODE_SERIALISER_H
