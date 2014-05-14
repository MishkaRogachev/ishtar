#include <QtTest/QtTest>


#include "node_test.h"

int main(int argc, char *argv[])
{
    {
        NodeTest test;
        QTest::qExec(&test);
    }

    return 0;
}
