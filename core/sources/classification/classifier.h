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
        Classifier(const QColor& penColor = Qt::black,
                   const QColor& brushColor = Qt::red,
                   const QString& textureId = QString());

        QColor penColor() const;
        void setPenColor(const QColor& penColor);

        QColor brushColor() const;
        void setBrushColor(const QColor& brushColor);

        QString textureId() const;
        void setTextureId(const QString& textureId);

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
        QColor m_penColor;
        QColor m_brushColor;
        QString m_textureId;
    };
}

#endif // CLASSIFIER_H
