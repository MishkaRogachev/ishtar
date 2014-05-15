#include "geometry_test.h"

#include "geometry.h"

using namespace situation;

void GeometryTest::equalType()
{
    Geometry geo1;
    Geometry geo2;

    QVERIFY(geo1 == geo2);

    geo1.setType(GeometryType::Line);

    QVERIFY(geo1 != geo2);

    geo2.setType(GeometryType::Line);

    QVERIFY(geo1 == geo2);

    geo1.setType(GeometryType::Collection);
    geo2.setType(GeometryType::Polygone);

    QVERIFY(geo1 != geo2);

}

void GeometryTest::equalPoints()
{
    Geometry geo1;
    Geometry geo2;

    geo1.setPoints( {{ {0.4, 12, 3,}, {1, 2, 3}, {56, -0.7, 4.5} }});

    QVERIFY(geo1 != geo2);

    geo2.setPoints( {{ {0.4, 12, 3,}, {1, 2, 3}, {56, -0.7, 4.5} }});

    QVERIFY(geo1 == geo2);

    geo2.setPoints( {{ {0.4, 12, 3}, {1, 2, 3}, {56, -0.7, 4.5} },
                     { {3.4, 1.2, 3.7}, {1.5, 2.4, 3.3}, {6.67, -0.7, 4.5} }});

    QVERIFY(geo1 != geo2);
    QVERIFY(geo2 != geo1);

}

void GeometryTest::equalChildren()
{
    GeometryPtr root1(new Geometry(GeometryType::Collection));
    GeometryPtr root2(new Geometry(GeometryType::Collection));

    QVERIFY(root1->isEqual(*root2));

    root1->rChildGeometries().append(GeometryPtr(new Geometry(GeometryType::Polygone)));
    root1->rChildGeometries().append(GeometryPtr(new Geometry(GeometryType::Line)));

    QVERIFY(!root1->isEqual(*root2));

    root2->rChildGeometries().append(GeometryPtr(new Geometry(GeometryType::Polygone)));
    root2->rChildGeometries().append(GeometryPtr(new Geometry(GeometryType::Line)));

    QVERIFY(root1->isEqual(*root2));

    root2->rChildGeometries().last()->rChildGeometries().append(
                GeometryPtr(new Geometry(GeometryType::Polygone)));

    QVERIFY(!root1->isEqual(*root2));

    GeometryPtr(new Geometry());

}
