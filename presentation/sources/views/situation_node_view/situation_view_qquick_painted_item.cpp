#include "situation_view_qquick_painted_item.h"

#include <QWheelEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>

#include "presenters/situation_node_presenter.h"
#include "drawers/situation_node_drawer/situation_node_drawer_qpainter.h"

namespace
{
    const double mouseWheelDegrees = 1200.0d;
}

using namespace presentation;

class SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItemPrivate
{
public:
    SituationNodePresenterPtr presenter;
    SituationNodeDrawerQPainter drawer;
};

SituationViewQQuickPaintedItem::
    SituationViewQQuickPaintedItem(QQuickItem* parent):
    QQuickPaintedItem(parent),
    ISituationNodeView(),
    d(new SituationViewQQuickPaintedItemPrivate())
{
    d->presenter.reset(new SituationNodePresenter(this));
    this->setCursor(QCursor(Qt::CrossCursor));
}

SituationViewQQuickPaintedItem::~SituationViewQQuickPaintedItem()
{
    delete d;
}

ISituationNodeDrawer* SituationViewQQuickPaintedItem::drawer() const
{
    return &d->drawer;
}

void presentation::SituationViewQQuickPaintedItem::paint(QPainter* painter)
{
    d->drawer.draw(painter, this->transformationMatrix());
}

void SituationViewQQuickPaintedItem::wheelEvent(QWheelEvent* event)
{
    qreal dS = 1 + (event->delta() / ::mouseWheelDegrees);

    QPointF sp = this->transformationMatrix().inverted().map(
                     QPointF(event->x(), event->y()));

    this->transformationMatrix().translate(sp.x(), sp.y());
    this->transformationMatrix().scale(dS, dS);
    this->transformationMatrix().translate(-sp.x(), -sp.y());

    this->update();
}


