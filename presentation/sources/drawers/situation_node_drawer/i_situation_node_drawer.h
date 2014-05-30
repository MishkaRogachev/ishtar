#ifndef I_SITUATION_NODE_DRAWER_H
#define I_SITUATION_NODE_DRAWER_H

#include "situation_traits.h"

namespace presentation
{
    class ISituationNodeDrawer
    {
    public:
        ISituationNodeDrawer();
        virtual ~ISituationNodeDrawer();

        virtual void setNode(const situation::NodePtr& node) = 0;
    };

    typedef QSharedPointer<ISituationNodeDrawer> SituationNodeDrawerPtr;
}
#endif // I_SITUATION_NODE_DRAWER_H
