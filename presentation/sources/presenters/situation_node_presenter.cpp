#include "situation_node_presenter.h"

#include <QDebug>

#include "node.h"
#include "node_serializer/json_node_serializer.h"
#include "classifier_serializer.h"

using namespace presentation;

class SituationNodePresenter::SituationNodePresenterPrivate
{
public:
    ISituationNodeView* const view;
    situation::NodePtr node;

    SituationNodePresenterPrivate(ISituationNodeView* view):
        view(view)
    {}
};

SituationNodePresenter::SituationNodePresenter(ISituationNodeView* view):
    d(new SituationNodePresenterPrivate(view))
{
    //TODO: demo code

    classification::ClassifierSerializer classifierSource;
    d->view->setClassifierMap(classifierSource.loadMap("example.json"));

    situation::JSonNodeSerializer nodeSource;
    d->node = nodeSource.load("example.geojson");
    d->view->setNode(d->node);
}

SituationNodePresenter::~SituationNodePresenter()
{
    delete d;
}
