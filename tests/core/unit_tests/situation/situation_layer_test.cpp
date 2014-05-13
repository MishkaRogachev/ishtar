#include "situation_layer_test.h"

#include "situation_layer.h"

using namespace situation;

void SituationLayerTest::addAndRemoveObjects()
{
    SituationLayer layer;

    layer.addObject(SituationObjectPtr());
    layer.removeObject(SituationObjectPtr());

    QVERIFY(layer.objects().isEmpty() == true);

    layer.addObject(SituationObjectPtr());
    layer.addObject(SituationObjectPtr());
    layer.addObject(SituationObjectPtr());
    layer.addObject(SituationObjectPtr());
    layer.addObject(SituationObjectPtr());
    layer.addObject(SituationObjectPtr());

    layer.removeObject(SituationObjectPtr());

    QVERIFY(layer.objects().count() == 5);

    layer.clear();

    QVERIFY(layer.objects().isEmpty() == true);

    SituationObjectPtrList list;

    list.append(SituationObjectPtr());
    list.append(SituationObjectPtr());
    list.append(SituationObjectPtr());
    list.append(SituationObjectPtr());
    list.append(SituationObjectPtr());

    layer.addObjects(list);

    QVERIFY(layer.objects().count() == 5);

    layer.removeObjects(list);

    QVERIFY(layer.objects().isEmpty() == true);
}
