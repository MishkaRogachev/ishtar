#ifndef SITUATION_OBJECT_H
#define SITUATION_OBJECT_H

#include "point.hpp"

namespace situation
{
    class SituationObject
    {
    public:
        SituationObject();
        virtual ~SituationObject();

        common::PointPtrList points() const;
        common::PointPtrList& rPoints() const;

    private:
        class SituationObjectPrivate;
        SituationObjectPrivate* d;

        SituationObject(const SituationObject& other) = delete;
        SituationObject& operator =(const SituationObject& other) = delete;
    };
}

#endif // SITUATION_OBJECT_H
