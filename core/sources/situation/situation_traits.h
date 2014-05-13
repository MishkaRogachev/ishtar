#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>

namespace situation
{
    class SituationLayer;
    class SituationMap;

    typedef QSharedPointer<SituationLayer> SituationLayerPtr;
    typedef QSharedPointer<SituationMap> SituationMapPtr;

    typedef QList<SituationLayerPtr> SituationLayerPtrList;
    typedef QList<SituationMapPtr> SituationMapPtrList;
}

#endif // SITUATION_TRAITS_H
