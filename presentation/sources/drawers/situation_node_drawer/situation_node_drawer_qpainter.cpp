#include "situation_node_drawer_qpainter.h"

#include <QPainter>
#include <QMatrix>

#include "draw_objects/draw_object_qpainter.h"

using namespace presentation;

class SituationNodeDrawerQPainter::SituationNodeDrawerQPainterPrivate
{
public:
    DrawObjectQPainterMap drawMap;
    classification::ClassifierPtrMap classifierMap;
};

SituationNodeDrawerQPainter::SituationNodeDrawerQPainter():
    ISituationNodeDrawer(),
    d(new SituationNodeDrawerQPainterPrivate())
{}

SituationNodeDrawerQPainter::~SituationNodeDrawerQPainter()
{
    delete d;
}

void SituationNodeDrawerQPainter::setNode(const situation::NodePtr& node)
{
    d->drawMap = DrawObjectQPainter::nodeToDrawObjectQPainterMap(node);
}

void SituationNodeDrawerQPainter::setClassifierMap(
        const classification::ClassifierPtrMap& classifierMap)
{
    d->classifierMap = classifierMap;
}

void SituationNodeDrawerQPainter::draw(QPainter* painter,
                                       const QMatrix& trasformationMatrix)
{
    painter->save();
    painter->setTransform(QTransform(trasformationMatrix));

    for (const DrawObjectQPainter& object: d->drawMap)
    {
        object.draw(painter, d->classifierMap);
    }

    painter->restore();
}
