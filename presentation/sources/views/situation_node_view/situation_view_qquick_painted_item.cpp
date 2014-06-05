#include "situation_view_qquick_painted_item.h"

#include <QWheelEvent>
#include <QMouseEvent>
#include <QTouchEvent>
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
    QPointF lastMousePosition;
    QList<QPointF> touchPoints;
};

SituationViewQQuickPaintedItem::
    SituationViewQQuickPaintedItem(QQuickItem* parent):
    QQuickPaintedItem(parent),
    ISituationNodeView(),
    d(new SituationViewQQuickPaintedItemPrivate())
{
    d->presenter.reset(new SituationNodePresenter(this));
    this->setFlag(QQuickItem::ItemHasContents, true);

    this->setCursor(QCursor(Qt::CrossCursor));
    this->setAcceptedMouseButtons(Qt::AllButtons);
    this->setFiltersChildMouseEvents(true);
    this->setAcceptHoverEvents(true);
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

    for (const QPointF& point: d->touchPoints)
    {
        painter->setPen(Qt::cyan);
        painter->setBrush(Qt::cyan);
        painter->drawEllipse(point, 25, 25);
    }
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

void SituationViewQQuickPaintedItem::mouseMoveEvent(QMouseEvent* event)
{
    if (d->lastMousePosition.isNull())
    {
        d->lastMousePosition = event->pos();
    }
    else if (event->buttons() == Qt::LeftButton)
    {
        QPointF dPosition = event->pos() - d->lastMousePosition;
        this->transformationMatrix().translate(
                    dPosition.x() / this->transformationMatrix().m11(),
                    dPosition.y() / this->transformationMatrix().m22());
        this->update();
    }

    d->lastMousePosition = event->pos();
}

void SituationViewQQuickPaintedItem::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event)
}

void SituationViewQQuickPaintedItem::mouseReleaseEvent(QMouseEvent* event)
{
    d->lastMousePosition = QPointF();
}

void presentation::SituationViewQQuickPaintedItem::touchEvent(QTouchEvent* event)
{
    d->touchPoints.clear();

    for (const QTouchEvent::TouchPoint& touchPoint: event->touchPoints())
    {
        d->touchPoints.append(touchPoint.pos());
    }
    this->update();
}
