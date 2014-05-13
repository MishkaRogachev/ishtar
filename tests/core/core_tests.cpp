#include <QtTest/QtTest>


#include "node_test.h"
#include "layer_test.h"
#include "map_test.h"

int main(int argc, char *argv[])
{
    {
        NodeTest test;
        QTest::qExec(&test);
    }
    {
        LayerTest test;
        QTest::qExec(&test);
    }
    {
        MapTest test;
        QTest::qExec(&test);
    }

    return 0;
}
