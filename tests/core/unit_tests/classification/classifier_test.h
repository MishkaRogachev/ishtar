#ifndef CLASSIFIER_TEST_H
#define CLASSIFIER_TEST_H

#include <QTest>

class ClassifierTest: public QObject
{
    Q_OBJECT

private slots:
    void variantConversion();
};

#endif // CLASSIFIER_TEST_H
