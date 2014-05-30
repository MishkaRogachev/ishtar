#include "classifier_serializer.h"

#include <QFile>
#include <QJsonDocument>
#include <QVariantMap>
#include <QTextStream>

using namespace classification;

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

QByteArray ClassifierSerializer::classifierToByteArray(const ClassifierPtr& classifier) const
{
    QJsonDocument document(this->classifierToJSonObject(classifier));
    return document.toJson();
}

ClassifierPtr ClassifierSerializer::load(const QString& filename) const
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return this->byteArrayToClassifier(file.readAll());
    }

    return ClassifierPtr();
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


