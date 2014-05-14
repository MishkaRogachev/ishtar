#include "node_test.h"

#include "node.h"
#include "bounding_box.h"
#include "geometry.h"

using namespace situation;

void NodeTest::equal()
{
    {
        Node node1;
        Node node2;

        QVERIFY(node1 == node2);
    }
    {
        Node node1;
        Node node2;

        node1.setBoundingBox(BoundingBoxPtr(new BoundingBox()));

        QVERIFY(node1 != node2);
    }
    {
        Node node1;
        Node node2;

        node1.setBoundingBox(BoundingBoxPtr(new BoundingBox()));
        node2.setBoundingBox(node1.boundingBox());

        QVERIFY(node1 == node2);
    }
    {
        Node node1;
        Node node2;

        node1.setGeometry(GeometryPtr(new Geometry()));

        QVERIFY(node1 != node2);
    }
    {
        Node node1;
        Node node2;

        node1.setGeometry(GeometryPtr(new Geometry()));
        node2.setGeometry(node1.geometry());

        QVERIFY(node1 == node2);
    }
}

void NodeTest::copy()
{
    Node node1;
    Node node2(node1);

    QVERIFY(node1 == node2);
}
