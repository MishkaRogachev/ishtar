#include "classifier.h"

#include <QVariant>
#include <QBuffer>
#include <QGradient>
#include <QDebug>

namespace keys
{
    const QString pen = "pen";
    const QString brush = "brush";
    const QString brushStyle = "brush_style";
    const QString color = "color";
    const QString gradient = "gradient";
    const QString gradientType = "gradient_type";
    const QString coordinateMode = "coordinate_mode";
    const QString spread = "spread";
    const QString position = "position";
    const QString stops = "stops";
    const QString matrix = "matrix";
    const QString texture = "texture";
    const QString capStyle = "cap_style";
    const QString penStyle = "pen_style";
    const QString width = "width";
    const QString joinStyle = "join_style";
}

namespace
{
    QVariant brushToVariant(const QBrush& brush)
    {
        QVariantMap map;

        if (brush.gradient())
        {
            QVariantMap gradient;

            gradient.insert(keys::gradientType,
                            static_cast<int>(brush.gradient()->type()));

            gradient.insert(keys::coordinateMode,
                            static_cast<int>(brush.gradient()->coordinateMode()));

            gradient.insert(keys::spread,
                            static_cast<int>(brush.gradient()->spread()));

            QVariantList gradientStops;

            for (const QGradientStop& stop: brush.gradient()->stops())
            {
                QVariantMap gradientStop;

                gradientStop.insert(keys::position, stop.first);
                gradientStop.insert(keys::color, stop.second);

                gradientStops.append(gradientStop);
            }

            gradient.insert(keys::stops, gradientStops);

            map.insert(keys::gradient, gradient);
        }

        if (!brush.matrix().isIdentity())
        {
            QVariantList matrix;

            matrix.append(brush.matrix().m11());
            matrix.append(brush.matrix().m12());
            matrix.append(brush.matrix().m21());
            matrix.append(brush.matrix().m22());
            matrix.append(brush.matrix().dx());
            matrix.append(brush.matrix().dy());

            map.insert(keys::matrix, matrix);
        }

        if (!brush.texture().isNull())
        {
            QByteArray textureArray;
            QBuffer textureBuffer(&textureArray);
            textureBuffer.open(QIODevice::WriteOnly);
            brush.texture().save(&textureBuffer, "PNG");
            textureBuffer.close();
            map.insert(keys::texture, textureArray);
        }

        map.insert(keys::brushStyle, static_cast<int>(brush.style()));
        map.insert(keys::color, brush.color());

        return QVariant(map);
    }

    QBrush variantToBrush(const QVariantMap& map)
    {
        QBrush brush;

        if (map.contains(keys::gradient))
        {
            QVariantMap gradientMap = map.value(keys::gradient).toMap();

            QGradient::Type type = static_cast<QGradient::Type>(
                       gradientMap.value(keys::gradientType,
                                         QGradient::NoGradient).toInt());
            QGradient gradient;

            switch (type) {
            case QGradient::LinearGradient:
                gradient = QLinearGradient();
                break;
            case QGradient::RadialGradient:
                gradient = QRadialGradient();
                break;
            case QGradient::ConicalGradient:
                gradient = QConicalGradient();
                break;
            default: break;
            }

            gradient.setCoordinateMode(static_cast<QGradient::CoordinateMode>(
                                           gradientMap.value(keys::coordinateMode,
                                           QGradient::LogicalMode).toInt()));

            gradient.setSpread(static_cast<QGradient::Spread>(
                                           gradientMap.value(keys::spread,
                                           QGradient::PadSpread).toInt()));

            QVariantList gradientStops = gradientMap.value(keys::stops).toList();

            for (const QVariant& stop: gradientStops)
            {
                const QVariantMap& stopMap = stop.toMap();
                gradient.setColorAt(stopMap.value(keys::position).toReal(),
                                    stopMap.value(keys::color).value<QColor>());
            }

            brush = QBrush(gradient);
        }

        if (map.contains(keys::matrix))
        {
            QVariantList matrix = map.value(keys::matrix).toList();

            if (matrix.count() >= 6 )
            {
                brush.setMatrix(QMatrix(matrix.at(0).toReal(),
                                        matrix.at(1).toReal(),
                                        matrix.at(2).toReal(),
                                        matrix.at(3).toReal(),
                                        matrix.at(4).toReal(),
                                        matrix.at(5).toReal()));
            }
        }

        if (map.contains(keys::texture))
        {
            QPixmap pixmap;
            pixmap.loadFromData(map.value(keys::texture).toByteArray(), "PNG");
            brush.setTexture(pixmap);
        }

        brush.setStyle(static_cast<Qt::BrushStyle>(
                           map.value(keys::brushStyle).toInt()));
        brush.setColor(map.value(keys::color).value<QColor>());

        return brush;
    }

    QVariant penToVariant(const QPen& pen)
    {
        QVariantMap map;

        map.insert(keys::brush, ::brushToVariant(pen.brush()));
        map.insert(keys::width, pen.widthF());
        map.insert(keys::penStyle, static_cast<int>(pen.style()));
        map.insert(keys::capStyle, static_cast<int>(pen.capStyle()));
        map.insert(keys::joinStyle, static_cast<int>(pen.joinStyle()));

        return QVariant(map);
    }

    QPen variantToPen(const QVariantMap& map)
    {
        QPen pen(::variantToBrush(map.value(keys::brush).toMap()),
                 map.value(keys::width).toReal(),
                 static_cast<Qt::PenStyle>(
                     map.value(keys::penStyle,
                               static_cast<int>(Qt::SolidLine)).toInt()),
                 static_cast<Qt::PenCapStyle>(
                     map.value(keys::capStyle,
                               static_cast<int>(Qt::SquareCap)).toInt()),
                 static_cast<Qt::PenJoinStyle>(
                     map.value(keys::joinStyle,
                               static_cast<int>(Qt::BevelJoin)).toInt()));

        return pen;
    }
}

using namespace classification;

Classifier::Classifier(const QPen& pen, const QBrush& brush):
    m_pen(pen),
    m_brush(brush)
{}

QPen Classifier::pen() const
{
    return m_pen;
}

void Classifier::setPen(const QPen& pen)
{
    m_pen = pen;
}

QBrush Classifier::brush() const
{
    return m_brush;
}

void Classifier::setBrush(const QBrush& brush)
{
    m_brush = brush;
}

QVariantMap Classifier::toVariantMap() const
{
    QVariantMap map;

    map.insert(keys::pen, ::penToVariant(m_pen));
    map.insert(keys::brush, ::brushToVariant(m_brush));

    return map;
}

Classifier Classifier::fromVariantMap(const QVariantMap& map)
{
    Classifier classifier;

    classifier.m_pen = ::variantToPen(map.value(keys::pen).toMap());
    classifier.m_brush = ::variantToBrush(map.value(keys::brush).toMap());

    return classifier;
}

bool Classifier::isEqual(const Classifier& other) const
{
    return (m_pen == other.m_pen &&
            m_brush == other.m_brush);
}
