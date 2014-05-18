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

    NodePtr node = serializer.load("test.geojson");

    QVERIFY(node);

    QVERIFY(node->id() == "root" );

    QVERIFY(node->boundingBox());
    QVERIFY(node->boundingBox()->isEqual(BoundingBox(0, 0, 0, 40, 40, 5)));

    QVERIFY(node->childNodes().count() == 3);

    QVERIFY(node->childNodes().first());
    QVERIFY(node->childNodes().first()->id() == "point");
    QVERIFY(node->childNodes().first()->geometry());
    QVERIFY(node->childNodes().first()->geometry()->type() ==
            GeometryType::Point);
    QVERIFY(node->childNodes().first()->geometry()->points() ==
            QVector3D3Vec ({{{QVector3D(30, 10, 5)}}}));

    QVERIFY(node->childNodes().at(1));
    QVERIFY(node->childNodes().at(1)->id() == "line");
    QVERIFY(node->childNodes().at(1)->geometry());
    QVERIFY(node->childNodes().at(1)->geometry()->type() ==
            GeometryType::Line);
    QVERIFY(node->childNodes().at(1)->geometry()->points() ==
            QVector3D3Vec ({{{QVector3D(30, 10, 0),
                              QVector3D(10, 30, 0),
                              QVector3D(40, 40, 0)}}}));

    QVERIFY(node->childNodes().at(2));
    QVERIFY(node->childNodes().at(2)->id() == "polygon");
    QVERIFY(node->childNodes().at(2)->geometry());
    QVERIFY(node->childNodes().at(2)->geometry()->type() ==
            GeometryType::Polygon);
    QVERIFY(node->childNodes().at(2)->geometry()->points() ==
            QVector3D3Vec ({{{QVector3D(30, 10, 5),
                              QVector3D(40, 40, 5),
                              QVector3D(20, 40, 5),
                              QVector3D(10, 20, 5),
                              QVector3D(30, 10, 5)}}}));
}

void JSonSerializerTest::saveAndReloadTest()
{
    JSonNodeSerializer serializer;

    NodePtr node = serializer.load("test.geojson");

    serializer.save(node, "tmp.geojson");

    NodePtr node2 = serializer.load("tmp.geojson");

    QVERIFY(node->isEqual(*node2));
}
