#ifndef SITUATION_MAP_H
#define SITUATION_MAP_H

#include "situation_traits.h"

namespace situation
{
    class Map
    {
    public:
        Map();
        virtual ~Map();

        void addLayer(const LayerPtr& layer);
        void addLayers(const LayerPtrList& layers);
        void removeLayer(const LayerPtr& layer);
        void removeLayers(const LayerPtrList& layers);
        void clear();
        void rehash();

        LayerPtrList layers() const;

    private:
        class SituationMapPrivate;
        SituationMapPrivate* d;

        Map(const Map& other) = delete;
        Map& operator =(const Map& other) = delete;
    };
}

#endif // SITUATION_MAP_H
