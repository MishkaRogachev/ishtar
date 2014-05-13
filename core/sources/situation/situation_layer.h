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

        void addObject(const SituationObjectPtr& object);
        void addObjects(const SituationObjectPtrList& objects);
        void removeObject(const SituationObjectPtr& object);
        void removeObjects(const SituationObjectPtrList& objects);
        void clear();

        SituationObjectPtrList objects() const;

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
