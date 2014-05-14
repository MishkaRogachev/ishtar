#include "json_serializer_test.h"

#include <QDebug>

#include "node_serializer/json_node_serializer.h"
#include "node.h"
#include "geometry.h"
#include "bounding_box.h"

using namespace situation;

NodePtr buildTestNode()
{
    GeometryPtr pointGeometry(new Geometry(GeometryType::Point,
                                  {{
                                      QVector3D(2.0, 3.0, 1.5),
                                      QVector3D(3.5, -1.0, 0.5)
                                  }}));

    BoundingBoxPtr bbox(new BoundingBox(2.0, -1.0, 0.5, 3.5, 3.0, 1.5));

    NodePtr rootNode(new Node("root"));
    rootNode->rChildNodes().append(NodePtr(new Node("line", pointGeometry, bbox)));

    return rootNode;
}

void JSonSerializerTest::jsonTextSerialization()
{
    JSonNodeSerializer serializer;

    NodePtr node = buildTestNode();
    NodePtr node2 = serializer.fromJSonObject(serializer.toJSonObject(node));

    QVERIFY(node.data() == node2.data());
}

void JSonSerializerTest::jsonBinarySerialization()
{
    JSonNodeSerializer serializer(JSonSerializationType::Binary);

    NodePtr node = buildTestNode();
    NodePtr node2 = serializer.fromJSonObject(serializer.toJSonObject(node));

    QVERIFY(node.data() == node2.data());
}

void JSonSerializerTest::byteArraySerialization()
{
    JSonNodeSerializer serializer;

    NodePtr node = buildTestNode();
    NodePtr node2 = serializer.fromByteArray(serializer.toByteArray(node));

    QVERIFY(node.data() == node2.data());
}

void JSonSerializerTest::saveAndLoad()
{
    JSonNodeSerializer serializer;
    NodePtr node = buildTestNode();

    serializer.save(node, "test.json");
    NodePtr node2 = serializer.load("test.json");

    QVERIFY(node.data() == node2.data());
}
