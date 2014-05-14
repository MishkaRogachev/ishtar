#ifndef JSON_GEOMETRY_PARSER_H
#define JSON_GEOMETRY_PARSER_H

#include <QJsonObject>
#include "situation_traits.h"

namespace situation
{
    class JSonGeometryParser
    {
    public:
        static QJsonObject parseGeometry(const GeometryPtr& geometry);
        static QString geometryTypeString(const GeometryPtr& geometry);

        static GeometryPtr parseJson(const QJsonObject& object);

    };
}

#endif // JSON_GEOMETRY_PARSER_H
