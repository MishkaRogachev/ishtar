#ifndef SITUATION_LAYER_H
#define SITUATION_LAYER_H

#include "situation_traits.h"

#include <QString>

namespace situation
{
    class SituationLayer
    {
    public:
        SituationLayer();
        virtual ~SituationLayer();

        SituationObjectPtrList objects() const;
        SituationObjectPtrList& rObjects() const;

        void setName(const QString& name);
        QString name() const;

    private:
        class SituationLayerPrivate;
        SituationLayerPrivate* d;

        SituationLayer(const SituationLayer& other) = delete;
        SituationLayer& operator =(const SituationLayer& other) = delete;
    };
}

#endif // SITUATION_LAYER_H
