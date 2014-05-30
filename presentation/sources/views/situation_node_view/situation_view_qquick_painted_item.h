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

    protected:
        virtual ISituationNodeDrawer* drawer() const override;

        virtual void paint(QPainter* painter) override;
        virtual void wheelEvent(QWheelEvent* event) override;

    private:
        class SituationViewQQuickPaintedItemPrivate;
        SituationViewQQuickPaintedItemPrivate* d;
    };
}
#endif // SITUATION_VIEW_QQUICK_PAINTED_ITEM_H
