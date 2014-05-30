#include "classifier.h"

#include <QVariant>
#include <QDebug>

namespace keys
{
    const QString penColor = "pen_color";
    const QString brushColor = "brush_color";
    const QString pixmap = "pixmap";
}

using namespace classification;

QPixmap Classifier::pixmap() const
{
    return m_pixmap;
}

void Classifier::setPixmap(const QPixmap& pixmap)
{
    m_pixmap = pixmap;
}

QColor Classifier::penColor() const
{
    return m_penColor;
}

void Classifier::setPenColor(const QColor& penColor)
{
    m_penColor = penColor;
}

QColor Classifier::brushColor() const
{
    return m_brushColor;
}

void Classifier::setBrushColor(const QColor& brushColor)
{
    m_brushColor = brushColor;
}

QVariantMap Classifier::toVariantMap() const
{
    QVariantMap map;

    map.insert(keys::penColor, m_penColor);
    map.insert(keys::brushColor, m_brushColor);
    map.insert(keys::pixmap, m_pixmap);

    return map;
}

Classifier Classifier::fromVariantMap(const QVariantMap& map)
{
    Classifier classifier;

    classifier.m_penColor = map.value(keys::penColor).value<QColor>();
    classifier.m_brushColor = map.value(keys::brushColor).value<QColor>();
    classifier.m_pixmap = map.value(keys::pixmap).value<QPixmap>();

    return classifier;
}

bool Classifier::isEqual(const Classifier& other) const
{
    if (m_penColor != other.m_penColor) return false;
    if (m_brushColor != other.m_brushColor) return false;
    if (m_pixmap.toImage() != other.m_pixmap.toImage()) return false;

    return true;
}
