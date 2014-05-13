#include "situation_layer.h"

#include "situation_object.h"

using namespace situation;

class Layer::SituationLayerPrivate
{
public:
    NodePtrList objects;
    QString name;
};

Layer::Layer(const NodePtrList& objects, const QString& name):
    d(new SituationLayerPrivate())
{
    d->objects = objects;
    d->name = name;
}

Layer::Layer(const Layer& other):
    d(new SituationLayerPrivate(*other.d))
{}

Layer::~Layer()
{
    delete d;
}

Layer& Layer::operator =(const Layer& other)
{
    delete d;
    d = new SituationLayerPrivate(*other.d);
    return *this;
}

NodePtrList Layer::objects() const
{
    return d->objects;
}

NodePtrList& Layer::rObjects() const
{
    return d->objects;
}

void Layer::setName(const QString& name)
{
    d->name = name;
}

QString Layer::name() const
{
    return d->name;
}
