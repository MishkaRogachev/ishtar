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
};

#endif // JSON_SERIALIZER_TEST_H
