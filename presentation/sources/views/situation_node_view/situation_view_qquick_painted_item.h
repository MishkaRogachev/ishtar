#ifndef SITUATION_VIEW_QQUICK_PAINTED_ITEM_H
#define SITUATION_VIEW_QQUICK_PAINTED_ITEM_H

#include  "i_situation_node_view.h"

#include <QQuickPaintedItem>

namespace presentation
{
    class SituationViewQQuickPaintedItem: public QQuickPaintedItem,
                                          public ISituationNodeView
    {
        Q_OBJECT

    public:
        explicit SituationViewQQuickPaintedItem(QQuickItem* parent = nullptr);
        virtual ~SituationViewQQuickPaintedItem() override;

        virtual void setRootNode(const situation::NodePtr& root) override;
        virtual void updateNode(const situation::NodePtr& node) override;

    protected:
        virtual void paint(QPainter* painter) override;

        virtual void wheelEvent(QWheelEvent* event) override;

    private:
        class SituationViewQQuickPaintedItemPrivate;
        SituationViewQQuickPaintedItemPrivate* d;
    };
}
#endif // SITUATION_VIEW_QQUICK_PAINTED_ITEM_H
