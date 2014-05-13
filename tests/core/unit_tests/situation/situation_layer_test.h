#ifndef SITUATION_LAYER_TEST_H
#define SITUATION_LAYER_TEST_H

#include <QTest>

class LayerTest: public QObject
{
    Q_OBJECT

private slots:
    void addAndRemoveObjects();
};

#endif // SITUATION_LAYER_TEST_H
