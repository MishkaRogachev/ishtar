#ifndef SITUATION_MAP_H
#define SITUATION_MAP_H

#include "situation_traits.h"

namespace situation
{
    class SituationMap
    {
    public:
        SituationMap();
        virtual ~SituationMap();

        void addLayer(const SituationLayerPtr& layer);

    private:
        class SituationMapPrivate;
        SituationMapPrivate* d;

        SituationMap(const SituationMap& other) = delete;
        SituationMap& operator =(const SituationMap& other) = delete;
    };
}

#endif // SITUATION_MAP_H
