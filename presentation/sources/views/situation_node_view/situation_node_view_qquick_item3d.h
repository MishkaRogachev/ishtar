#ifndef SITUATION_NODE_VIEW_QQUICK_ITEM3D_H
#define SITUATION_NODE_VIEW_QQUICK_ITEM3D_H

#include "i_situation_node_view.h"

#include <QQuickItem3D>

namespace presentation
{
    class SituationNodeViewQQuickItem3D: public QQuickItem3D,
                                         public ISituationNodeView
    {
        Q_OBJECT

    public:
        explicit SituationNodeViewQQuickItem3D(QQuickItem* parent = nullptr);
        virtual ~SituationNodeViewQQuickItem3D() override;

    protected:
        virtual void draw(QGLPainter* painter) override;

    private:
        class SituationNodeViewQQuickItem3DPrivate;
        SituationNodeViewQQuickItem3DPrivate* d;
    };
}

#endif // SITUATION_NODE_VIEW_QQUICK_ITEM3D_H
