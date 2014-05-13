#ifndef SITUATION_LAYER_H
#define SITUATION_LAYER_H

#include "situation_traits.h"

#include <QString>

namespace situation
{
    class SituationLayer
    {
    public:
        SituationLayer(const SituationObjectPtrList& objects =
                SituationObjectPtrList(), const QString& name = QString());
        SituationLayer(const SituationLayer& other);

        virtual ~SituationLayer();

        SituationLayer& operator =(const SituationLayer& other);

        SituationObjectPtrList objects() const;
        SituationObjectPtrList& rObjects() const;

        void setName(const QString& name);
        QString name() const;

    private:
        class SituationLayerPrivate;
        SituationLayerPrivate* d;
    };
}

#endif // SITUATION_LAYER_H
