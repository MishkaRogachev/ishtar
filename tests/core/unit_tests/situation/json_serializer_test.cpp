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

    QVERIFY(node->boundingBox());
    QVERIFY(node->boundingBox()->isEqual(BoundingBox(-10,-10, 0, 10, 10, 10)));

    QVERIFY(node->childNodes().count() == 2);

    QVERIFY(node->childNodes().first());
    QVERIFY(node->childNodes().first()->id() == "line");
    QVERIFY(node->childNodes().first()->geometry());
    QVERIFY(node->childNodes().first()->geometry()->type() ==
            GeometryType::Line);
    QVERIFY(node->childNodes().first()->geometry()->points() ==
            QVector3D3Vec ({{{QVector3D(-10, -10, 0), QVector3D(10,10,0)}}}));

    QVERIFY(node->childNodes().at(1));
    QVERIFY(node->childNodes().at(1)->id() == "point");
    QVERIFY(node->childNodes().at(1)->geometry());
    QVERIFY(node->childNodes().at(1)->geometry()->type() ==
            GeometryType::Point);
    QVERIFY(node->childNodes().at(1)->geometry()->points() ==
            QVector3D3Vec ({{{QVector3D(0, -0.5, 0.5)}}}));
}
