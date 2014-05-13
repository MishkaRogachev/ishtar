#include <QtTest/QtTest>

#include "map_test.h"
#include "layer_test.h"

int main(int argc, char *argv[])
{
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
