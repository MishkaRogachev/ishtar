#ifndef SITUATION_LAYER_TEST_H
#define SITUATION_LAYER_TEST_H

#include <QTest>

class SituationLayerTest: public QObject
{
    Q_OBJECT

private slots:
    void addAndRemoveObjects();
};

#endif // SITUATION_LAYER_TEST_H
