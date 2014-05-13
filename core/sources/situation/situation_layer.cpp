#include "situation_layer.h"

#include "situation_object.h"

using namespace situation;

class SituationLayer::SituationLayerPrivate
{
public:
    SituationObjectPtrList objects;
    QString name;
};

SituationLayer::SituationLayer(const SituationObjectPtrList& objects, const QString& name):
    d(new SituationLayerPrivate())
{
    d->objects = objects;
    d->name = name;
}

SituationLayer::SituationLayer(const SituationLayer& other):
    d(new SituationLayerPrivate(*other.d))
{}

SituationLayer::~SituationLayer()
{
    delete d;
}

SituationLayer& SituationLayer::operator =(const SituationLayer& other)
{
    delete d;
    d = new SituationLayerPrivate(*other.d);
    return *this;
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
