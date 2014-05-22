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

void ClassifierSerializerTest::saveAndLoaad()
{
    ClassifierSerializer serializer;

    ClassifierPtr cl1(new Classifier());

    serializer.save(cl1, "tmp.json");

    ClassifierPtr cl2 = serializer.load("tmp.json");

    QVERIFY(cl1->isEqual(*cl2));
}
