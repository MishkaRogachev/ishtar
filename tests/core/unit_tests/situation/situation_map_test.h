#ifndef SITUATION_MAP_TEST_H
#define SITUATION_MAP_TEST_H

#include <QTest>

class SituationMapTest: public QObject
{
    Q_OBJECT

private slots:
    void addAndRemoveLayers();
};

#endif //SITUATION_MAP_TEST_H
