#include "classifier_serializer_test.h"

#include <QDebug>

#include "classifier_serializer.h"
#include "classifier.h"

using namespace classification;

void ClassifierSerializerTest::jsonConversion()
{
    ClassifierSerializer serializer;

    ClassifierPtr cl1(new Classifier());

    ClassifierPtr cl2 = serializer.jSonObjectToClassifier(
                            serializer.classifierToJSonObject(cl1));

    QVERIFY(cl1->isEqual(*cl2));
}

void ClassifierSerializerTest::byteArrayConversion()
{
    ClassifierSerializer serializer;

    ClassifierPtr cl1(new Classifier());

    ClassifierPtr cl2 = serializer.byteArrayToClassifier(
                            serializer.classifierToByteArray(cl1));

    QVERIFY(cl1->isEqual(*cl2));
}

void ClassifierSerializerTest::saveAndLoad()
{
    ClassifierSerializer serializer;

    ClassifierPtr cl1(new Classifier());

    serializer.save(cl1, "tmp.json");

    ClassifierPtr cl2 = serializer.load("tmp.json");

    QVERIFY(cl1->isEqual(*cl2));
}

void ClassifierSerializerTest::jsonMapConversion()
{
    ClassifierSerializer serializer;

    ClassifierPtrMap map;
    map.insert("test1", ClassifierPtr(new Classifier()));
    map.insert("test2", ClassifierPtr(new Classifier()));
    map.insert("test3", ClassifierPtr(new Classifier()));

    ClassifierPtrMap map2 = serializer.jSonObjectToClassifierMap(
                                serializer.classifierMapToJSonObject(map));

    QVERIFY(map.value("test1")->isEqual(*map2.value("test1")));
    QVERIFY(map.value("test2")->isEqual(*map2.value("test2")));
    QVERIFY(map.value("test3")->isEqual(*map2.value("test3")));
}

void ClassifierSerializerTest::byteArrayMapConversion()
{
    ClassifierSerializer serializer;

    ClassifierPtrMap map;
    map.insert("test", ClassifierPtr(new Classifier()));

    ClassifierPtrMap map2 = serializer.byteArrayToClassifierMap(
                                serializer.classifierMapToByteArray(map));

    QVERIFY(map.value("test")->isEqual(*map2.value("test")));
}

void ClassifierSerializerTest::saveAndLoadMap()
{
    ClassifierSerializer serializer;

    ClassifierPtrMap map;

    QLinearGradient gradient;
    gradient.setColorAt(0, Qt::green);
    gradient.setColorAt(1, Qt::blue);

    QBrush brush(gradient);
    brush.setMatrix(QMatrix(0.23, 0.17, 34.0, -0.25, 45.73, -256.7));

    ClassifierPtr classifier1(new Classifier(QColor("#8BC941")));
    classifier1->setBrush(brush);

    map.insert("field", classifier1);
    map.insert("road", ClassifierPtr(new Classifier(QColor("#2C3E50"), QColor("#C4CBCF"))));

    serializer.saveMap(map, "testClassifier.json");
    ClassifierPtrMap map2 = serializer.loadMap("testClassifier.json");

    QVERIFY(map.value("field")->isEqual(*map2.value("field")));
    QVERIFY(map.value("road")->isEqual(*map2.value("road")));
}
