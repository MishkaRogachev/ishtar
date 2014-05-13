#ifndef SITUATION_OBJECT_H
#define SITUATION_OBJECT_H

namespace situation
{
    class SituationObject
    {
    public:
        SituationObject();
        virtual ~SituationObject();



    private:
        SituationObject(const SituationObject& other) = delete;
        SituationObject& operator =(const SituationObject& other) = delete;
    };
}

#endif // SITUATION_OBJECT_H
