#ifndef CLASSIFICATION_TRAITS_H
#define CLASSIFICATION_TRAITS_H

#include <QSharedPointer>
#include <QMap>
#include <QString>

namespace classification
{
    class Classifier;

    typedef QSharedPointer<Classifier> ClassifierPtr;
    typedef QMap<QString, ClassifierPtr> ClassifierPtrMap;
}

#endif // CLASSIFICATION_TRAITS_H
