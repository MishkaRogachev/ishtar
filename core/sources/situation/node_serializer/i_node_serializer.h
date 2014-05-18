#ifndef I_NODE_SERIALIZER_H
#define I_NODE_SERIALIZER_H

#include "situation_traits.h"

#include <QByteArray>

namespace situation
{
    class INodeSerializer
    {
    public:
        bool save(const NodePtr& node, const QString& name) const;
        NodePtr load(const QString& name) const;

        virtual QByteArray nodePtrToByteArray(const NodePtr& node) const = 0;
        virtual NodePtr byteArrayToNodePtr(const QByteArray& array) const = 0;
    };
}

#endif // I_NODE_SERIALIZER_H
