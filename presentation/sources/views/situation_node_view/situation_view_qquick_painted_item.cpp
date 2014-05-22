#include "situation_view_qquick_painted_item.h"

#include <QWheelEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QCursor>

#include "presenters/situation_node_presenter.h"
#include "geometry_parsers/draw_path_geometry_parser.h"

using namespace presentation;

class SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItemPrivate
{
public:
    PaintedNodeDrawMap drawMap;
    SituationNodePresenterPtr presenter;
    classification::ClassifierPtr classifier;
};

SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItem(QQuickItem* parent) :
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

void SituationViewQQuickPaintedItem::setRootNode(const situation::NodePtr& root)
{
    DrawPathGeometryParser parser;
    d->drawMap = parser.generateDrawMap(root, d->classifier);
    this->update();
}

void SituationViewQQuickPaintedItem::updateNode(const situation::NodePtr& node)
{
//    if (node && d->drawMap.contains(node->id()))
//    {
//        //TODO: update geometry on node
//        this->update();
    //    }
}

void SituationViewQQuickPaintedItem::setClassifier(
        const classification::ClassifierPtr& classifier)
{
    d->classifier = classifier;
}

void presentation::SituationViewQQuickPaintedItem::paint(QPainter* painter)
{
    painter->setTransform(QTransform(m_transformationMatrix));

    for (const PaintedNodeDrawObject& drawObject: d->drawMap.values())
    {
        drawObject.draw(painter);
    }
}

void SituationViewQQuickPaintedItem::wheelEvent(QWheelEvent* event)
{
    qreal dS = 1 + (event->delta() / 1200.0d);

    QPointF sp = m_transformationMatrix.inverted().map(
                     QPointF(event->x(), event->y()));

    m_transformationMatrix.translate(sp.x(), sp.y());
    m_transformationMatrix.scale(dS, dS);
    m_transformationMatrix.translate(-sp.x(), -sp.y());

    this->update();
}


