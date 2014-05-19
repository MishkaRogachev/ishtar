#include "json_serializer_test.h"

#include <QDebug>

#include "node_serializer/json_node_serializer.h"
#include "node.h"
#include "geometry.h"
#include "bounding_box.h"

using namespace situation;

void JSonSerializerTest::serializePoint()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("point",
                 GeometryPtr(new Geometry(GeometryType::Point,
                            QVector3D3Vec({{{ QVector3D(30, 10, 15) }}})))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializeLine()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("line",
                 GeometryPtr(new Geometry(GeometryType::Line,
                            QVector3D3Vec({{{ QVector3D(30, 10, 15),
                                              QVector3D(10, 30, 15),
                                              QVector3D(40, 40, 15) }}})))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializePolygon()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("polygon",
                 GeometryPtr(new Geometry(GeometryType::Polygon,
                            QVector3D3Vec({{{ QVector3D(35, 10, 15),
                                              QVector3D(45, 45, 15),
                                              QVector3D(15, 40, 15),
                                              QVector3D(10, 20, 15),
                                              QVector3D(35, 10, 15)
                                            },
                                            { QVector3D(20, 30, 15),
                                              QVector3D(35, 35, 15),
                                              QVector3D(30, 20, 15),
                                              QVector3D(20, 30, 15) }
                                           }})))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializeMultiPoint()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("multi_point",
                 GeometryPtr(new Geometry(GeometryType::MultiPoint,
                            QVector3D3Vec({{{ QVector3D(30, 10, 15),
                                              QVector3D(20, 30, 15),
                                              QVector3D(30, 20, 15) }}})))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializeMultiLine()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("multi_line",
                 GeometryPtr(new Geometry(GeometryType::MultiLine,
                            QVector3D3Vec({{{ QVector3D(35, 10, 15),
                                              QVector3D(20, 45, 15),
                                              QVector3D(15, 20, 15)
                                            },
                                            { QVector3D(40, 40, 15),
                                              QVector3D(30, 25, 15),
                                              QVector3D(15, 20, 15),
                                              QVector3D(20, 10, 15) }
                                           }})))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializeMultiPolygon()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("multi_polygon",
                 GeometryPtr(new Geometry(GeometryType::MultiPolygon,
                            QVector3D3Vec({{{ QVector3D(45, 10, 15),
                                              QVector3D(35, 45, 15),
                                              QVector3D(15, 50, 15),
                                              QVector3D(10, 30, 15),
                                            },
                                            { QVector3D(25, 20, 15),
                                              QVector3D(35, 30, 15),
                                              QVector3D(30, 25, 15),
                                              QVector3D(30, 35, 15)
                                            }
                                           },
                                           {
                                            { QVector3D(15, 5, 15),
                                              QVector3D(40, 10, 15),
                                              QVector3D(40, 5, 15)
                                            }
                                           }
                                          })))));

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::serializeCollection()
{
    JSonNodeSerializer serializer;

    NodePtr node(new Node("collection"));

    QList<GeometryPtr> geoList;

    geoList.append(GeometryPtr(new Geometry(GeometryType::MultiPoint,
                        QVector3D3Vec({{{ QVector3D(30, 10, 15),
                                          QVector3D(20, 30, 15),
                                          QVector3D(30, 20, 15) }}}))));

    geoList.append(GeometryPtr(new Geometry(GeometryType::Line,
                        QVector3D3Vec({{{ QVector3D(30, 10, 15),
                                          QVector3D(30, 20, 15) }}}))));

    geoList.append(GeometryPtr(new Geometry(GeometryType::Point,
                        QVector3D3Vec({{{ QVector3D(30, 10, 15) }}}))));

    GeometryPtr geo(new Geometry(GeometryType::Collection));
    geo->setChildGeometries(geoList);
    node->setGeometry(geo);

    NodePtr node2 = serializer.byteArrayToNodePtr(
                        serializer.nodePtrToByteArray(node));

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

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

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}

void JSonSerializerTest::saveAndReload()
{
    JSonNodeSerializer serializer;

    NodePtr node = serializer.load("test.geojson");

    serializer.save(node, "tmp.geojson");

    NodePtr node2 = serializer.load("tmp.geojson");

    QVERIFY(node->isEqual(*node2));

    if (!serializer.errors().isEmpty()) qDebug() << serializer.errors();
}
