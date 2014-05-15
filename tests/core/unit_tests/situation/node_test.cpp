#include "node_test.h"

#include "node.h"
#include "bounding_box.h"
#include "geometry.h"

using namespace situation;

void NodeTest::copy()
{
    Node node1;
    Node node2(node1);

    QVERIFY(node1 == node2);
}

void NodeTest::equal()
{
    Node node1;
    Node node2;

    QVERIFY(node1 == node2);

    node1.setGeometry(GeometryPtr(new Geometry()));

    QVERIFY(node1 != node2);

    node2.setGeometry(GeometryPtr(new Geometry()));

    QVERIFY(node1 == node2);

    node1.setBoundingBox(BoundingBoxPtr(new BoundingBox()));

    QVERIFY(node1 != node2);

    node2.setBoundingBox(BoundingBoxPtr(new BoundingBox()));

    QVERIFY(node1 == node2);
}

void NodeTest::equalChildren()
{
    Node node1;
    Node node2;

    node1.rChildNodes().append(NodePtr(new Node()));

    QVERIFY(node1 != node2);

    node2.rChildNodes().append(NodePtr(new Node()));

    QVERIFY(node1 == node2);

}
