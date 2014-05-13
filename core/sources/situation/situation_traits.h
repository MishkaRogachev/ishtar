#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>

namespace situation
{
    class SituationLayer;
    class SituationMap;

    typedef QSharedPointer<SituationLayer> SituationLayerPtr;
    typedef QSharedPointer<SituationMap> SituationMapPtr;
}

#endif // SITUATION_TRAITS_H
