#include "situation_map.h"

#include <QMap>
#include <QDebug>

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
    Id id = (d->layers.keys().isEmpty()) ? 1 : d->layers.lastKey() + 1;

    d->layers.insert(id, layer);
}

void SituationMap::addLayers(const SituationLayerPtrList& layers)
{
    for (const SituationLayerPtr& layer: layers)
    {
        this->addLayer(layer);
    }
}

void SituationMap::removeLayer(const SituationLayerPtr& layer)
{
    Id id = d->layers.key(layer, 0);
    if (id == 0) return;

    d->layers.remove(id);

    if (!d->layers.empty()) this->rehash();
}

void SituationMap::removeLayers(const SituationLayerPtrList& layers)
{
    for (const SituationLayerPtr& layer: layers)
    {
        Id id = d->layers.key(layer, 0);
        if (id == 0) continue;

        d->layers.remove(id);
    }

    if (!d->layers.empty()) this->rehash();
}

void SituationMap::clear()
{
    d->layers.clear();
}

void SituationMap::rehash()
{
    SituationLayerPtrList valueList;
    for (const SituationLayerPtr& value: d->layers.values())
    {
        valueList.append(value);
    }

    this->clear();
    this->addLayers(valueList);
}

SituationLayerPtrList SituationMap::layers() const
{
    return d->layers.values();
}
