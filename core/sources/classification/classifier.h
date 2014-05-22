#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "classification_traits.h"

#include <QColor>

namespace classification
{
    //TODO: classifiator value by id
    class Classifier
    {
    public:
        QColor penColor = Qt::black;
        QColor brushColor = Qt::black;

        QVariantMap toVariantMap() const;

        static Classifier fromVariantMap(const QVariantMap& map);

        bool isEqual(const Classifier& other) const;
        inline friend bool operator==(const Classifier& left,
                                      const Classifier& right)
        {
            return left.isEqual(right);
        }
        inline friend bool operator!=(const Classifier& left,
                                      const Classifier& right)
        {
            return !left.isEqual(right);
        }
    };
}

#endif // CLASSIFIER_H
