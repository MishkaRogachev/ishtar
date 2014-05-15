#include <QtTest/QtTest>

#include "geometry_test.h"
#include "bounding_box_test.h"
#include "node_test.h"
#include "json_serializer_test.h"

int main(int argc, char *argv[])
{
    QVector<QObject*> tests;

    tests.append(new GeometryTest());
    tests.append(new BoundingBoxTest());
    tests.append(new NodeTest());

    tests.append(new JSonSerializerTest());

    for (QObject* test: tests)
    {
        QTest::qExec(test);
        delete test;
    }

    return 0;
}
