#ifndef I_SITUATION_NODE_VIEW_H
#define I_SITUATION_NODE_VIEW_H

#include "situation_traits.h"
#include "classification_traits.h"

class QMatrix;

namespace presentation
{
    class ISituationNodeDrawer;

    class ISituationNodeView
    {
    public:
        ISituationNodeView();
        ~ISituationNodeView();

        void setNode(const situation::NodePtr& node);

    protected:
        QMatrix& transformationMatrix() const;

        virtual ISituationNodeDrawer* drawer() const = 0;

    private:
        class ISituationNodeViewPrivate;
        ISituationNodeViewPrivate* d;
    };
}

#endif // I_SITUATION_NODE_VIEW_H
