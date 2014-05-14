#ifndef JSON_GEOMETRY_PARSER_H
#define JSON_GEOMETRY_PARSER_H

#include <QJsonObject>
#include "situation_traits.h"

namespace situation
{
    class JSonGeometryParser
    {
    public:
        static QJsonObject parse(const GeometryPtr& geometry);
        static QString geometryTypeString(const GeometryPtr& geometry);
    };
}

#endif // JSON_GEOMETRY_PARSER_H
