#ifndef I_NODE_SERIALIZER_H
#define I_NODE_SERIALIZER_H

#include "situation_traits.h"

#include <QByteArray>
#include <QStringList>

namespace situation
{
    class INodeSerializer
    {
    public:
        bool save(const NodePtr& node, const QString& filename) const;
        NodePtr load(const QString& filename) const;

        virtual QByteArray nodeToByteArray(const NodePtr& node) const = 0;
        virtual NodePtr byteArrayToNode(const QByteArray& array) const = 0;
    };
}

#endif // I_NODE_SERIALIZER_H
