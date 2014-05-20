#include "situation_view_qquick_painted_item.h"

#include <QPainter>
#include <QMap>
#include <QPair>
#include <QVector>

#include "presenters/situation_node_presenter.h"

#include "node.h"

namespace
{
    enum class PaintType
    {
        Point,
        Line,
        Polygon
    };
}

using namespace presentation;

class SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItemPrivate
{
public:
    QMap<QString, QPair< PaintType, QVector <QPointF> >> geometry;
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

void SituationViewQQuickPaintedItem::setNode(const situation::NodePtr& node)
{
    //TODO: node to painte geometry data!
    //d->nodeToGeometry(node);
    this->update();
}

void presentation::SituationViewQQuickPaintedItem::paint(QPainter* painter)
{
    painter->fillRect(QRect(0, 0, this->width(), this->height()), Qt::blue);

    for (auto nodeGeometry: d->geometry.values())
    {
        switch (nodeGeometry.first)
        {
        case PaintType::Point:
            painter->drawPoints(nodeGeometry.second.data(),
                                nodeGeometry.second.count());
            break;
        case PaintType::Line:
            painter->drawPoints(nodeGeometry.second);
            break;
        case PaintType::Polygon:
            painter->drawPoints(nodeGeometry.second.data(),
                                nodeGeometry.second.count());
            break;
        }
    }
}
