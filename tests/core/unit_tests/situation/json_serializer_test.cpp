#include "json_serializer_test.h"

#include <QDebug>

#include "node_serializer/json_node_serializer.h"
#include "node.h"
#include "geometry.h"
#include "bounding_box.h"

using namespace situation;

void JSonSerializerTest::loadFromFile()
{
    JSonNodeSerializer serializer;

    NodePtr node = serializer.load("test.json");

    QVERIFY(node);
    QVERIFY(node->id() == "root" );
    QVERIFY(node->boundingBox()->isEqual(BoundingBox(-10,-10, 0, 10, 10, 10)));
    QVERIFY(node->childNodes().count() == 1);
    QVERIFY(node->childNodes().first());
    QVERIFY(node->childNodes().first()->id() == "line");
}
