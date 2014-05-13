#include "situation_layer.h"

#include "i_situation_object.h"

using namespace situation;

class SituationLayer::SituationLayerPrivate
{
public:
    SituationObjectPtrList objects;
};

SituationLayer::SituationLayer():
    d(new SituationLayerPrivate())
{}

SituationLayer::~SituationLayer()
{
    delete d;
}

SituationObjectPtrList SituationLayer::objects() const
{
    return d->objects;
}
