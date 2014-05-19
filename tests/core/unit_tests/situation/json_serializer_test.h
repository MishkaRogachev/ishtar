#ifndef JSON_SERIALIZER_TEST_H
#define JSON_SERIALIZER_TEST_H

#include <QTest>

class JSonSerializerTest: public QObject
{
    Q_OBJECT

private slots:
    void serializePoint();
    void serializeLine();
    void serializePolygon();
    void serializeMultiPoint();
    void serializeMultiLine();
    void serializeMultiPolygon();
    void serializeCollection();
    void loadFromFile();
    void saveAndReload();
//    void jsonTextSerialization();
//    void jsonBinarySerialization();
//    void byteArraySerialization();
//    void saveAndLoad();
};

#endif // JSON_SERIALIZER_TEST_H
