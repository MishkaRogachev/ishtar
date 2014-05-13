#include "situation_object.h"

using namespace situation;

class SituationObject::SituationObjectPrivate
{
public:
    common::PointPtrList points;
};

SituationObject::SituationObject():
    d(new SituationObjectPrivate())
{}

SituationObject::~SituationObject()
{
    delete d;
}

common::PointPtrList SituationObject::points() const
{
    return d->points;
}

common::PointPtrList& SituationObject::rPoints() const
{
    return d->points;
}
