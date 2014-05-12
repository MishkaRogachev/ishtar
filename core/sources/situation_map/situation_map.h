#ifndef MAP_H
#define MAP_H

#include <memory>

namespace core
{
    class SituationMap
    {
    public:
        SituationMap();

    private:
        class SituationMapPrivate;
        std::unique_ptr<SituationMapPrivate> d;
    };
}

#endif // MAP_H
