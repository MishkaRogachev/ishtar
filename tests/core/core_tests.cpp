#include <QtTest/QtTest>

#include "node_test.h"
#include "json_serializer_test.h"

int main(int argc, char *argv[])
{
    {
        NodeTest test;
        QTest::qExec(&test);
    }
    {
        JSonSerializerTest test;
        QTest::qExec(&test);
    }

    return 0;
}
