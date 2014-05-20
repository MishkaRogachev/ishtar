#include "situation_node_presenter.h"

using namespace presentation;

class SituationNodePresenter::SituationNodePresenterPrivate
{
public:
    const ISituationNodeView* view;

    SituationNodePresenterPrivate(ISituationNodeView* view):
        view(view)
    {}
};

SituationNodePresenter::SituationNodePresenter(ISituationNodeView* view):
    d(new SituationNodePresenterPrivate(view))
{}

SituationNodePresenter::~SituationNodePresenter()
{
    delete d;
}
