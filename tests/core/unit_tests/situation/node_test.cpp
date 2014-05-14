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

        node1.setBoundingBox(BoundingBoxPtr(new BoundingBox(0,1,2,3,4,5.0001)));
        node2.setBoundingBox(BoundingBoxPtr(new BoundingBox(0,1,2,3,4,5.0001)));

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

        node1.setGeometry(GeometryPtr(new Geometry(GeometryType::Point,
        {{
            QVector3D(2.45, 3.2345, -1567.555)
        }})));
        node2.setGeometry(GeometryPtr(new Geometry(GeometryType::Point,
        {{
            QVector3D(2.4500, 3.2345, -1567.555)
        }})));

        QVERIFY(node1 == node2);
    }
}

void NodeTest::copy()
{
    Node node1;
    Node node2(node1);

    QVERIFY(node1 == node2);
}
