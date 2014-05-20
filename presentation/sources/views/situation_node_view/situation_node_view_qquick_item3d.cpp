#include "situation_node_view_qquick_item3d.h"

#include "presenters/situation_node_presenter.h"

using namespace presentation;

class SituationNodeViewQQuickItem3D::SituationNodeViewQQuickItem3DPrivate
{
public:
    SituationNodePresenterPtr presenter;
    QGLSceneNode* viewNode = nullptr;
};

SituationNodeViewQQuickItem3D::
    SituationNodeViewQQuickItem3D(QQuickItem* parent):
    QQuickItem3D(parent),
    ISituationNodeView(),
    d(new SituationNodeViewQQuickItem3DPrivate())
{
    d->presenter.reset(new SituationNodePresenter(this));
}

SituationNodeViewQQuickItem3D::~SituationNodeViewQQuickItem3D()
{
    delete d;
}

void SituationNodeViewQQuickItem3D::draw(QGLPainter* painter)
{
    if (d->viewNode) d->viewNode->draw(painter);

    QQuickItem3D::draw(painter);
}
