#ifndef JSON_GEOMETRY_PARSER_H
#define JSON_GEOMETRY_PARSER_H

#include <QJsonObject>
#include "situation_traits.h"

namespace situation
{
    class JSonGeometryParser
    {
    public:
        static QJsonObject toJSon(const GeometryPtr& geometry);

        static GeometryPtr toGeometry(const QJsonObject& object);
    };
}

#endif // JSON_GEOMETRY_PARSER_H
