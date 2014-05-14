#ifndef JSON_NODE_SERIALISER_H
#define JSON_NODE_SERIALISER_H

#include "i_node_serializer.h"

#include <QJsonObject>

namespace situation
{
    class JSonNodeSerializer : public INodeSerializer
    {
    public:
        JSonNodeSerializer(bool isCompact = false);

        virtual QByteArray toByteArray(const NodePtr& node) const override;

        QJsonObject toJSonObject(const NodePtr& node) const;

    private:
        bool isCompact;
    };
}
#endif // JSON_NODE_SERIALISER_H
