#include "situation_map.h"

#include <QMap>

#include "defs.h"
#include "situation_layer.h"

using namespace defs;
using namespace situation;

class SituationMap::SituationMapPrivate
{
public:
    QMap <Id, SituationLayerPtr> layers;
};

SituationMap::SituationMap():
    d(new SituationMapPrivate())
{}

SituationMap::~SituationMap()
{
    delete d;
}

void SituationMap::addLayer(const SituationLayerPtr& layer)
{
    Q_ASSERT(d->layers.keys() + 1 >= std::numeric_limits<Id>::max());
    d->layers.insert(++d->layers.keys().last(), layer);
}
