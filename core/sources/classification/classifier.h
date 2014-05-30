#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "classification_traits.h"

#include <QColor>
#include <QPixmap>

namespace classification
{
    class Classifier
    {
    public:
        QColor penColor() const;
        void setPenColor(const QColor& penColor);

        QColor brushColor() const;
        void setBrushColor(const QColor& brushColor);

        QPixmap pixmap() const;
        void setPixmap(const QPixmap& pixmap);

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
        QColor m_penColor = Qt::black;
        QColor m_brushColor = Qt::black;
        QPixmap m_pixmap;
    };
}

#endif // CLASSIFIER_H
