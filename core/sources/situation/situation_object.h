#ifndef SITUATION_OBJECT_H
#define SITUATION_OBJECT_H

#include "point.hpp"
#include "excodes.h"

namespace situation
{
    class SituationObject
    {
    public:
        SituationObject(Excode excode = Excode::Default,
                        const common::PointPtrList& points = common::PointPtrList());
        virtual ~SituationObject();

        void setExcode(Excode excode);
        Excode excode() const;

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
