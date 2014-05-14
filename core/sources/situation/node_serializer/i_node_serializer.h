#ifndef I_NODE_SERIALIZER_H
#define I_NODE_SERIALIZER_H

#include "situation_traits.h"

namespace situation
{
    class INodeSerializer
    {
    public:
        INodeSerializer();

        virtual QByteArray serialize(const NodePtr& node) const = 0;
    };
}

#endif // I_NODE_SERIALIZER_H
