#ifndef CLASSIFICATION_TRAITS_H
#define CLASSIFICATION_TRAITS_H

#include <QSharedPointer>
#include <QHash>
#include <QString>

namespace classification
{
    class Classifier;

    typedef QSharedPointer<Classifier> ClassifierPtr;
}

#endif // CLASSIFICATION_TRAITS_H
