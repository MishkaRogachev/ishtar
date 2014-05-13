#include "layer_test.h"

#include "layer.h"

using namespace situation;

void LayerTest::copy()
{
    Layer layer;
    Layer layer2(layer);

    QVERIFY(layer2 == layer);
}

void LayerTest::equal()
{
    Layer layer;
    Layer layer2;

    layer2 = layer;

    QVERIFY(layer2 == layer);
}
