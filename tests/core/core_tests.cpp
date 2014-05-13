#include <QtTest/QtTest>

#include "situation_map_test.h"

int main()
{
    QList<QObject*> tests;

    tests.append(new SituationMapTest());

    for (QObject* test: tests)
    {
        QTest::qExec(test);
        delete test;
    }

   return 0;
}
