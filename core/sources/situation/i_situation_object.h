#ifndef I_SITUATION_OBJECT_H
#define I_SITUATION_OBJECT_H

namespace situation
{
    class ISituationObject
    {
    public:
        ISituationObject();
        virtual ~ISituationObject();

        ISituationObject(const ISituationObject& other) = delete;
        ISituationObject& operator =(const ISituationObject& other) = delete;
    };
}

#endif // I_SITUATION_OBJECT_H
