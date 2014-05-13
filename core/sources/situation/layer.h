#ifndef SITUATION_LAYER_H
#define SITUATION_LAYER_H

#include "situation_traits.h"

#include <QString>

namespace situation
{
    class Layer
    {
    public:
        Layer(const NodePtrList& objects =
                NodePtrList(), const QString& name = QString());
        Layer(const Layer& other);

        virtual ~Layer();

        Layer& operator =(const Layer& other);
        bool operator==(const Layer& other);

        NodePtrList objects() const;
        NodePtrList& rObjects() const;

        void setName(const QString& name);
        QString name() const;

    private:
        class SituationLayerPrivate;
        SituationLayerPrivate* d;
    };
}

#endif // SITUATION_LAYER_H
