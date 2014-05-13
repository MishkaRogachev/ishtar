#ifndef MAP_H
#define MAP_H

namespace core
{
    class SituationMap
    {
    public:
        SituationMap();
        ~SituationMap();

        void debug();

    private:
        class SituationMapPrivate;
        SituationMapPrivate* d;
    };
}

#endif // MAP_H
