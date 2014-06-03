#ifndef CLASSIFIER_SERIALIZER_TEST_H
#define CLASSIFIER_SERIALIZER_TEST_H

#include <QTest>

class ClassifierSerializerTest: public QObject
{
    Q_OBJECT

private slots:
    void jsonConversion();
    void byteArrayConversion();
    void saveAndLoad();

    void jsonMapConversion();
    void byteArrayMapConversion();
    void saveAndLoadMap();
};

#endif // CLASSIFIER_SERIALIZER_TEST_H
