#ifndef CLASSIFIER_SERIALIZER_H
#define CLASSIFIER_SERIALIZER_H

#include "classifier.h"

#include <QByteArray>
#include <QJsonObject>

namespace classification
{
    class ClassifierSerializer
    {
    public:
        ClassifierPtr load(const QString& filename) const;
        bool save(const ClassifierPtr& classifier, const QString& filename) const;

        QByteArray classifierToByteArray(const ClassifierPtr& classifier) const;
        ClassifierPtr byteArrayToClassifier(const QByteArray& array) const;

        QJsonObject classifierToJSonObject(const ClassifierPtr& classifier) const;
        ClassifierPtr jSonObjectToClassifier(const QJsonObject& object) const;
    };
}
#endif // CLASSIFIER_SERIALIZER_H
