#include "json_serializer_test.h"

#include "node_serializer/json_node_serializer.h"
#include "node.h"

using namespace situation;

NodePtr buildTestNode()
{
    NodePtr rootNode(new Node("root"));
    rootNode->childNodes().append(NodePtr(new Node("point",
                                                   Geometry(
                                                    GeometryType::Point,
                                                    {{
                                                        QVector3D(2.0, 3.0, 1.5)
                                                    }}))));

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
