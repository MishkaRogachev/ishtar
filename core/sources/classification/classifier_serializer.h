#ifndef CLASSIFIER_SERIALIZER_H
#define CLASSIFIER_SERIALIZER_H

#include "classification_traits.h"

#include <QByteArray>
#include <QJsonObject>

namespace classification
{
    class ClassifierSerializer
    {
    public:
        ClassifierPtr load(const QString& filename) const;
        bool save(const ClassifierPtr& classifier,
                  const QString& filename) const;

        QByteArray classifierToByteArray(
                const ClassifierPtr& classifier) const;
        ClassifierPtr byteArrayToClassifier(const QByteArray& array) const;

        QJsonObject classifierToJSonObject(
                const ClassifierPtr& classifier) const;
        ClassifierPtr jSonObjectToClassifier(const QJsonObject& object) const;

        ClassifierPtrMap loadMap(const QString& filename) const;
        bool saveMap(const ClassifierPtrMap& map,
                  const QString& filename) const;

        QByteArray classifierMapToByteArray(
                const ClassifierPtrMap& classifierMap) const;
        ClassifierPtrMap byteArrayToClassifierMap(
                const QByteArray& array) const;

        QJsonObject classifierMapToJSonObject(
                const ClassifierPtrMap& classifierMap) const;
        ClassifierPtrMap jSonObjectToClassifierMap(
                const QJsonObject& object) const;
    };
}
#endif // CLASSIFIER_SERIALIZER_H
