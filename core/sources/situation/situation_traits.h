#ifndef SITUATION_TRAITS_H
#define SITUATION_TRAITS_H

#include <QSharedPointer>
#include <QList>

namespace situation
{
    class SituationObject;
    class SituationLayer;
    class SituationMap;

    typedef QSharedPointer<SituationObject> SituationObjectPtr;
    typedef QSharedPointer<SituationLayer> SituationLayerPtr;
    typedef QSharedPointer<SituationMap> SituationMapPtr;

    typedef QList<SituationObjectPtr> SituationObjectPtrList;
    typedef QList<SituationLayerPtr> SituationLayerPtrList;
    typedef QList<SituationMapPtr> SituationMapPtrList;
}

#endif // SITUATION_TRAITS_H
