#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "classification_traits.h"

#include <QPen>
#include <QBrush>

namespace classification
{
    class Classifier
    {
    public:
        Classifier(const QPen& pen = QPen(), const QBrush& brush = QBrush());

        QPen pen() const;
        void setPen(const QPen& pen);

        QBrush brush() const;
        void setBrush(const QBrush& brush);

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

    private:
        QPen m_pen;
        QBrush m_brush;
    };
}

#endif // CLASSIFIER_H
