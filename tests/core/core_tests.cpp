#include <QtTest/QtTest>

#include "situation_map_test.h"

int main(int argc, char *argv[])
{
    {
        SituationMapTest test;
        QTest::qExec(&test);
    }

    return 0;
}
