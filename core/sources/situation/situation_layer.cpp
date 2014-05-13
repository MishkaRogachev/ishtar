#include "situation_layer.h"

#include "i_situation_object.h"

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

void SituationLayer::addObject(const SituationObjectPtr& object)
{
    d->objects.append(object);
}

void SituationLayer::addObjects(const SituationObjectPtrList& objects)
{
    d->objects.append(objects);
}

void SituationLayer::removeObject(const SituationObjectPtr& object)
{
    d->objects.removeOne(object);
}

void SituationLayer::removeObjects(const SituationObjectPtrList& objects)
{
    for (const SituationObjectPtr& object: objects)
    {
        d->objects.removeOne(object);
    }
}

void SituationLayer::clear()
{
    d->objects.clear();
}

SituationObjectPtrList SituationLayer::objects() const
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
