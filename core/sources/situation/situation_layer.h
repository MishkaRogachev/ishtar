#ifndef SITUATION_LAYER_H
#define SITUATION_LAYER_H

#include "situation_traits.h"

namespace situation
{
    class SituationLayer
    {
    public:
        SituationLayer();
        virtual ~SituationLayer();

        SituationObjectPtrList objects() const;

    private:
        class SituationLayerPrivate;
        SituationLayerPrivate* d;

        SituationLayer(const SituationLayer& other) = delete;
        SituationLayer& operator =(const SituationLayer& other) = delete;
    };
}

#endif // SITUATION_LAYER_H
