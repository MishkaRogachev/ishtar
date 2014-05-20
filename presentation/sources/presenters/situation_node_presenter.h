#ifndef SITUATION_NODE_PRESENTER_H
#define SITUATION_NODE_PRESENTER_H

#include "views/situation_node_view/i_situation_node_view.h"

#include <QScopedPointer>

namespace presentation
{
    class SituationNodePresenter
    {
    public:
        SituationNodePresenter(ISituationNodeView* view);
        ~SituationNodePresenter();

    private:
        class SituationNodePresenterPrivate;
        SituationNodePresenterPrivate* d;
    };

    typedef QScopedPointer<SituationNodePresenter> SituationNodePresenterPtr;
}

#endif // SITUATION_NODE_PRESENTER_H
