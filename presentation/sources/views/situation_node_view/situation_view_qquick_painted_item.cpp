#include "situation_view_qquick_painted_item.h"

#include <QPainter>

#include "presenters/situation_node_presenter.h"

using namespace presentation;

class SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItemPrivate
{
public:
    SituationNodePresenterPtr presenter;
};

SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItem(QQuickItem* parent) :
    QQuickPaintedItem(parent),
    ISituationNodeView(),
    d(new SituationViewQQuickPaintedItemPrivate())
{
    d->presenter.reset(new SituationNodePresenter(this));
}

SituationViewQQuickPaintedItem::~SituationViewQQuickPaintedItem()
{
    delete d;
}


void presentation::SituationViewQQuickPaintedItem::paint(QPainter* painter)
{
    painter->fillRect(QRect(0, 0, this->width(), this->height()), Qt::blue);
}
