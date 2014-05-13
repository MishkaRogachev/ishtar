#include <QtTest/QtTest>

#include "situation_map_test.h"
#include "situation_layer_test.h"

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
