#include "situation_map_test.h"

#include "situation_map.h"
#include "situation_layer.h"

using namespace situation;

void SituationMapTest::addAndRemoveLayers()
{
    SituationMap map;

    map.addLayer(SituationLayerPtr());
    map.removeLayer(SituationLayerPtr());

    QVERIFY(map.layers().isEmpty() == true);

    map.addLayer(SituationLayerPtr(new SituationLayer()));
    map.addLayer(SituationLayerPtr(new SituationLayer()));
    map.addLayer(SituationLayerPtr(new SituationLayer()));
    map.addLayer(SituationLayerPtr());
    map.addLayer(SituationLayerPtr(new SituationLayer()));
    map.addLayer(SituationLayerPtr(new SituationLayer()));

    map.removeLayer(SituationLayerPtr());

    QVERIFY(map.layers().count() == 5);

    map.clear();

    QVERIFY(map.layers().isEmpty() == true);

    SituationLayerPtrList list;

    list.append(SituationLayerPtr(new SituationLayer()));
    list.append(SituationLayerPtr(new SituationLayer()));
    list.append(SituationLayerPtr(new SituationLayer()));
    list.append(SituationLayerPtr(new SituationLayer()));
    list.append(SituationLayerPtr(new SituationLayer()));


    map.addLayers(list);

    QVERIFY(map.layers().count() == 5);

    map.removeLayers(list);

    QVERIFY(map.layers().isEmpty() == true);
}
