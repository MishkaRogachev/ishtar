#include "i_situation_node_view.h"

#include <QMatrix>

#include "../../drawers/situation_node_drawer/i_situation_node_drawer.h"

using namespace presentation;

class ISituationNodeView::ISituationNodeViewPrivate
{
public:
    //TODO: to drawer
    QMatrix transformationMatrix {
        35279.1, 0, 0,
        35279.1, -1.31176e+06,-1.97569e+06
    };
};

ISituationNodeView::ISituationNodeView():
    d(new ISituationNodeViewPrivate())
{}

ISituationNodeView::~ISituationNodeView()
{
    delete d;
}

void ISituationNodeView::setNode(const situation::NodePtr& node)
{
    this->drawer()->setNode(node);
}

QMatrix& ISituationNodeView::transformationMatrix() const
{
    return d->transformationMatrix;
}

