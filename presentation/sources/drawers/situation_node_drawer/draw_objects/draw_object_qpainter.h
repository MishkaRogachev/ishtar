#ifndef DRAW_OBJECT_QPAINTER_H
#define DRAW_OBJECT_QPAINTER_H

#include <QMap>

#include "situation_traits.h"

class QPainter;

namespace presentation
{
    class DrawObjectQPainter;

    typedef QMap<QString, DrawObjectQPainter> DrawObjectQPainterMap;

    class DrawObjectQPainter
    {
    public:
        DrawObjectQPainter();
        DrawObjectQPainter(const DrawObjectQPainter& other);
        ~DrawObjectQPainter();

        static DrawObjectQPainter nodeToDrawObjectQPainter(
                const situation::NodePtr& node);
        static DrawObjectQPainterMap nodeToDrawObjectQPainterMap(
                const situation::NodePtr& node);

        void draw(QPainter* painter) const;

    private:
        class DrawObjectQPainterPrivate;
        DrawObjectQPainterPrivate* d;
    };
}
#endif // DRAW_OBJECT_QPAINTER_H
