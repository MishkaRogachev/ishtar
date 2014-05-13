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
        void addLayers(const SituationLayerPtrList& layers);
        void removeLayer(const SituationLayerPtr& layer);
        void removeLayers(const SituationLayerPtrList& layers);
        void clear();
        void rehash();

        SituationLayerPtrList layers() const;

    private:
        class SituationMapPrivate;
        SituationMapPrivate* d;

        SituationMap(const SituationMap& other) = delete;
        SituationMap& operator =(const SituationMap& other) = delete;
    };
}

#endif // SITUATION_MAP_H
