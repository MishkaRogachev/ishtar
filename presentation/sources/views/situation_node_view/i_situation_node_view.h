#ifndef I_SITUATION_NODE_VIEW_H
#define I_SITUATION_NODE_VIEW_H

#include "situation_traits.h"

namespace presentation
{
    class ISituationNodeView
    {
    public:
        virtual void setNode(const situation::NodePtr& node) = 0;

    };
}

#endif // I_SITUATION_NODE_VIEW_H
