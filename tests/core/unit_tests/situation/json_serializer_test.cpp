#include "json_serializer_test.h"

#include <QDebug>

#include "node_serializer/json_node_serializer.h"
#include "node.h"

using namespace situation;

NodePtr buildTestNode()
{
    GeometryPtr pointGeometry(new Geometry(GeometryType::Point,
                                  {{
                                      QVector3D(2.0, 3.0, 1.5)
                                  }}));

    NodePtr rootNode(new Node("root"));
    rootNode->rChildNodes().append(NodePtr(new Node("point", pointGeometry)));

    return rootNode;
}

void JSonSerializerTest::jsonSerialization()
{
    JSonNodeSerializer serializer;

    NodePtr node = buildTestNode();
    NodePtr node2 = serializer.fromJSonObject(serializer.toJSonObject(node));

    QVERIFY(node = node2);
}

void JSonSerializerTest::byteArraySerialization()
{
    JSonNodeSerializer serializer;

    NodePtr node = buildTestNode();
    NodePtr node2 = serializer.fromByteArray(serializer.toByteArray(node));

    QVERIFY(node = node2);
}

void JSonSerializerTest::saveAndLoad()
{
    JSonNodeSerializer serializer;
    NodePtr node = buildTestNode();

    serializer.save(node, "test.json");
    NodePtr node2 = serializer.load("test.json");

    QVERIFY(node = node2);
}
