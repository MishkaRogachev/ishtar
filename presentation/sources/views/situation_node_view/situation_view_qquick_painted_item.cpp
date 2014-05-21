#include "situation_view_qquick_painted_item.h"

#include <QPainter>
#include <QMap>
#include <QPair>
#include <QVector>

#include "presenters/situation_node_presenter.h"
#include "geometry_parsers/draw_path_geometry_parser.h"

using namespace presentation;

class SituationViewQQuickPaintedItem::SituationViewQQuickPaintedItemPrivate
{
public:
    NodeDrawMap drawMap;
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

void SituationViewQQuickPaintedItem::setRootNode(const situation::NodePtr& root)
{
    //TODO: node to painte geometry data!
    //d->nodeToGeometry(node);
    DrawPathGeometryParser parser;
    d->drawMap = parser.generateDrawMap(root);
    this->update();
}

void SituationViewQQuickPaintedItem::updateNode(const situation::NodePtr& node)
{
//    if (node && d->geometry.contains(node->id()))
//    {
//        //TODO: update geometry on node
//        this->update();
//    }
}

void presentation::SituationViewQQuickPaintedItem::paint(QPainter* painter)
{
    //TODO: refactor to self draw(QPainter* painter, Scale* scale) function
    for (const NodeDrawObject& drawObject: d->drawMap.values())
    {
        painter->setPen(drawObject.pen);
        painter->setBrush(drawObject.brush);

        for (const QPainterPath& path: drawObject.painterPaths)
        {
            painter->drawPath(path);
        }
    }
}
