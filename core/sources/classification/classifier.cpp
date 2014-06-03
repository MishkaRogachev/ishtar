#include "classifier.h"

#include <QVariant>
#include <QDebug>

namespace keys
{
    const QString penColor = "pen_color";
    const QString brushColor = "brush_color";
    const QString textureId = "texture_id";
}

using namespace classification;

Classifier::Classifier(const QColor& penColor,
                       const QColor& brushColor,
                       const QString& textureId):
    m_penColor(penColor),
    m_brushColor(brushColor),
    m_textureId(textureId)
{}

QString Classifier::textureId() const
{
    return m_textureId;
}

void Classifier::setTextureId(const QString& textureId)
{
    m_textureId = textureId;
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
    map.insert(keys::textureId, m_textureId);

    return map;
}

Classifier Classifier::fromVariantMap(const QVariantMap& map)
{
    Classifier classifier;

    classifier.m_penColor = map.value(keys::penColor).value<QColor>();
    classifier.m_brushColor = map.value(keys::brushColor).value<QColor>();
    classifier.m_textureId = map.value(keys::textureId).value<QString>();

    return classifier;
}

bool Classifier::isEqual(const Classifier& other) const
{
    return (m_penColor == other.m_penColor &&
            m_brushColor == other.m_brushColor &&
            m_textureId == other.m_textureId);
}
