#include "map.h"

#include <QMap>
#include <QDebug>

#include "defs.h"
#include "layer.h"

using namespace defs;
using namespace situation;

class Map::SituationMapPrivate
{
public:
    QMap <Id, LayerPtr> layers;
};

Map::Map():
    d(new SituationMapPrivate())
{}

Map::~Map()
{
    delete d;
}

void Map::addLayer(const LayerPtr& layer)
{
    Id id = (d->layers.keys().isEmpty()) ? 1 : d->layers.lastKey() + 1;

    d->layers.insert(id, layer);
}

void Map::addLayers(const LayerPtrList& layers)
{
    for (const LayerPtr& layer: layers)
    {
        this->addLayer(layer);
    }
}

void Map::removeLayer(const LayerPtr& layer)
{
    Id id = d->layers.key(layer, 0);
    if (id == 0) return;

    d->layers.remove(id);

    if (!d->layers.empty()) this->rehash();
}

void Map::removeLayers(const LayerPtrList& layers)
{
    for (const LayerPtr& layer: layers)
    {
        Id id = d->layers.key(layer, 0);
        if (id == 0) continue;

        d->layers.remove(id);
    }

    if (!d->layers.empty()) this->rehash();
}

void Map::clear()
{
    d->layers.clear();
}

void Map::rehash()
{
    LayerPtrList valueList;
    for (const LayerPtr& value: d->layers.values())
    {
        valueList.append(value);
    }

    this->clear();
    this->addLayers(valueList);
}

LayerPtrList Map::layers() const
{
    return d->layers.values();
}
