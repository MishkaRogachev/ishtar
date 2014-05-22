#include "classifier.h"

#include <QVariant>
#include <QDebug>

namespace keys
{
    const QString penColor = "pen_color";
    const QString brushColor = "brush_color";
}

using namespace classification;

QVariantMap Classifier::toVariantMap() const
{
    QVariantMap map;

    map.insert(keys::penColor, penColor);
    map.insert(keys::brushColor, brushColor);

    return map;
}

Classifier Classifier::fromVariantMap(const QVariantMap& map)
{
    Classifier classifier;

    classifier.penColor = map.value(keys::penColor).value<QColor>();
    classifier.brushColor = map.value(keys::brushColor).value<QColor>();

    return classifier;
}

bool Classifier::isEqual(const Classifier& other) const
{
    if (penColor != other.penColor) return false;
    if (brushColor != other.brushColor) return false;

    return true;
}
