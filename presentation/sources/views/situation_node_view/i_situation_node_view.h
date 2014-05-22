#ifndef I_SITUATION_NODE_VIEW_H
#define I_SITUATION_NODE_VIEW_H

#include <QMatrix>

#include "situation_traits.h"
#include "classification_traits.h"

namespace presentation
{
    class ISituationNodeView
    {
    public:
        virtual void setRootNode(const situation::NodePtr& root) = 0;
        virtual void updateNode(const situation::NodePtr& node) = 0;
        virtual void setClassifier(const classification::ClassifierPtr& hash) = 0;

        QMatrix transformationMatrix() const;

    protected:
        QMatrix m_transformationMatrix {
            35279.1, 0, 0,
            35279.1, -1.31176e+06,-1.97569e+06};
    };
}

#endif // I_SITUATION_NODE_VIEW_H
