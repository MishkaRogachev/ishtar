#ifndef JSON_SERIALIZER_TEST_H
#define JSON_SERIALIZER_TEST_H

#include <QTest>

class JSonSerializerTest: public QObject
{
    Q_OBJECT

private slots:
    void jsonSerialization();
    void byteArraySerialization();
    void saveAndLoad();
};

#endif // JSON_SERIALIZER_TEST_H
