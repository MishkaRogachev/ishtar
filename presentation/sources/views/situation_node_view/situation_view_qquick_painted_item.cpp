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
    QLineF oldTouchLine;
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

    painter->setPen(Qt::cyan);
    painter->setBrush(Qt::cyan);

    if (!d->oldTouchLine.isNull())
    {
        painter->drawLine(d->oldTouchLine);
    }
}

void SituationViewQQuickPaintedItem::wheelEvent(QWheelEvent* event)
{
    this->scaleMapToPoint(1 + (event->delta() / ::mouseWheelDegrees),
                       QPointF(event->x(), event->y()));
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
        this->translateMap(event->pos() - d->lastMousePosition);
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

void SituationViewQQuickPaintedItem::touchEvent(QTouchEvent* event)
{
    if (event->touchPoints().count() == 2)
    {
        QLineF touchLine;
        touchLine.setP1(event->touchPoints().first().pos());
        touchLine.setP2(event->touchPoints().last().pos());

        if (!d->oldTouchLine.isNull())
        {
            QPointF center((touchLine.p2().x() + touchLine.p1().x()) / 2,
                           (touchLine.p2().y() + touchLine.p1().y()) / 2);

            QPointF oldCenter((d->oldTouchLine.p2().x() +
                               d->oldTouchLine.p1().x()) / 2,
                              (d->oldTouchLine.p2().y() +
                               d->oldTouchLine.p1().y()) / 2);

            this->translateMap(center - oldCenter);
            this->scaleMapToPoint(
                        touchLine.length() / d->oldTouchLine.length(),
                        center);
        }

        d->oldTouchLine = touchLine;
    }
    else
    {
        d->oldTouchLine = QLine();
        QQuickPaintedItem::touchEvent(event);
    }

    this->update();
}
