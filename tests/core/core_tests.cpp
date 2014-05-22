#include <QtTest/QtTest>

#include "geometry_test.h"
#include "bounding_box_test.h"
#include "node_test.h"
#include "json_serializer_test.h"

#include "classifier_test.h"
#include "classifier_serializer_test.h"

int main(int argc, char *argv[])
{
    QVector<QObject*> tests;

    tests.append(new GeometryTest());
    tests.append(new BoundingBoxTest());
    tests.append(new NodeTest());
    tests.append(new JSonSerializerTest());

    tests.append(new ClassifierTest());
    tests.append(new ClassifierSerializerTest());

    for (QObject* test: tests)
    {
        QTest::qExec(test);
        delete test;
    }

    return 0;
}
