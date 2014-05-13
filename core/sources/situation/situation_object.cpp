#include "situation_object.h"

using namespace situation;

class SituationObject::SituationObjectPrivate
{
public:
    Excode excode;
    common::PointPtrList points;
};

SituationObject::SituationObject(Excode excode, const common::PointPtrList& points):
    d(new SituationObjectPrivate())
{
    d->excode = excode;
    d->points = points;
}

SituationObject::~SituationObject()
{
    delete d;
}

void SituationObject::setExcode(Excode excode)
{
    d->excode = excode;
}

Excode SituationObject::excode() const
{
    return d->excode;
}

common::PointPtrList SituationObject::points() const
{
    return d->points;
}

common::PointPtrList& SituationObject::rPoints() const
{
    return d->points;
}


