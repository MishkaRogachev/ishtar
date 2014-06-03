#ifndef SITUATION_NODE_DRAWER_QPAINTER_H
#define SITUATION_NODE_DRAWER_QPAINTER_H

#include "i_situation_node_drawer.h"

class QPainter;
class QMatrix;

namespace presentation
{
    class SituationNodeDrawerQPainter: public ISituationNodeDrawer
    {
    public:
        SituationNodeDrawerQPainter();
        ~SituationNodeDrawerQPainter();

        virtual void setNode(const situation::NodePtr& node) override;
        virtual void setClassifierMap(const classification::ClassifierPtrMap&
                                      classifierMap) override;

        void draw(QPainter* painter, const QMatrix& trasformationMatrix);

    private:
        class SituationNodeDrawerQPainterPrivate;
        SituationNodeDrawerQPainterPrivate* d;
    };
}

#endif // SITUATION_NODE_DRAWER_QPAINTER_H
