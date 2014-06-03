#include "classifier_serializer.h"

#include <QFile>
#include <QJsonDocument>
#include <QVariantMap>
#include <QTextStream>

#include "classifier.h"

using namespace classification;

ClassifierPtr ClassifierSerializer::load(const QString& filename) const
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return this->byteArrayToClassifier(file.readAll());
    }

    return ClassifierPtr();
}

bool ClassifierSerializer::save(const ClassifierPtr& classifier,
                                const QString& filename) const
{
    QFile file(filename);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out << this->classifierToByteArray(classifier);
        return true;
    }
    return false;
}

QByteArray ClassifierSerializer::classifierToByteArray(
        const ClassifierPtr& classifier) const
{
    QJsonDocument document(this->classifierToJSonObject(classifier));
    return document.toJson();
}

ClassifierPtr ClassifierSerializer::byteArrayToClassifier(
        const QByteArray& array) const
{
    return this->jSonObjectToClassifier(
                QJsonDocument::fromJson(array).object());
}

QJsonObject ClassifierSerializer::classifierToJSonObject(
        const ClassifierPtr& classifier) const
{
    return QJsonObject::fromVariantMap(classifier->toVariantMap());
}

ClassifierPtr ClassifierSerializer::jSonObjectToClassifier(
                const QJsonObject& object) const
{
    return ClassifierPtr(
                new Classifier(Classifier::fromVariantMap(
                                   object.toVariantMap())));
}

ClassifierPtrMap ClassifierSerializer::loadMap(const QString& filename) const
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return this->byteArrayToClassifierMap(file.readAll());
    }

    return ClassifierPtrMap();
}

bool ClassifierSerializer::saveMap(const ClassifierPtrMap& map,
                                const QString& filename) const
{
    QFile file(filename);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out << this->classifierMapToByteArray(map);
        return true;
    }
    return false;
}

QByteArray ClassifierSerializer::classifierMapToByteArray(
        const ClassifierPtrMap& classifierMap) const
{
    QJsonDocument document(this->classifierMapToJSonObject(classifierMap));
    return document.toJson();
}

ClassifierPtrMap ClassifierSerializer::byteArrayToClassifierMap(
        const QByteArray& array) const
{
    return this->jSonObjectToClassifierMap(
                QJsonDocument::fromJson(array).object());
}

QJsonObject ClassifierSerializer::classifierMapToJSonObject(
        const ClassifierPtrMap& classifierMap) const
{
    QVariantMap map;

    for (const QString& key: classifierMap.keys())
    {
        map.insert(key, classifierMap.value(key)->toVariantMap());
    }

    return QJsonObject::fromVariantMap(map);
}

ClassifierPtrMap ClassifierSerializer::jSonObjectToClassifierMap(
        const QJsonObject& object) const
{
    ClassifierPtrMap map;

    for (const QString& key: object.keys())
    {
        map.insert(key, ClassifierPtr(
                       new Classifier(Classifier::fromVariantMap(
                                      object.value(key).toVariant().toMap()))));
    }
    return map;
}


