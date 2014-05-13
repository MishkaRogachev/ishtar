#include "situation_map.h"

#include <QDebug>

using namespace core;

class SituationMap::SituationMapPrivate
{
public:

};

SituationMap::SituationMap():
    d(new SituationMapPrivate())
{}

SituationMap::~SituationMap()
{
    delete d;
}

void SituationMap::debug()
{
    qDebug() << "debug";
}
