#include "situation_layer.h"

#include "situation_object.h"

using namespace situation;

class SituationLayer::SituationLayerPrivate
{
public:
    SituationObjectPtrList objects;
    QString name;
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

SituationObjectPtrList& SituationLayer::rObjects() const
{
    return d->objects;
}

void SituationLayer::setName(const QString& name)
{
    d->name = name;
}

QString SituationLayer::name() const
{
    return d->name;
}
