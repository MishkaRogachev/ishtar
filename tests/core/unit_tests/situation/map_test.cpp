#include "map_test.h"

#include "map.h"
#include "layer.h"

using namespace situation;

void MapTest::addAndRemoveLayers()
{
    Map map;

    map.addLayer(LayerPtr());
    map.removeLayer(LayerPtr());

    QVERIFY(map.layers().isEmpty() == true);

    map.addLayer(LayerPtr(new Layer()));
    map.addLayer(LayerPtr(new Layer()));
    map.addLayer(LayerPtr(new Layer()));
    map.addLayer(LayerPtr());
    map.addLayer(LayerPtr(new Layer()));
    map.addLayer(LayerPtr(new Layer()));

    map.removeLayer(LayerPtr());

    QVERIFY(map.layers().count() == 5);

    map.clear();

    QVERIFY(map.layers().isEmpty() == true);

    LayerPtrList list;

    list.append(LayerPtr(new Layer()));
    list.append(LayerPtr(new Layer()));
    list.append(LayerPtr(new Layer()));
    list.append(LayerPtr(new Layer()));
    list.append(LayerPtr(new Layer()));


    map.addLayers(list);

    QVERIFY(map.layers().count() == 5);

    map.removeLayers(list);

    QVERIFY(map.layers().isEmpty() == true);
}
