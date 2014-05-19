#ifndef SITUATION_NODE_VIEW_ITEM_H
#define SITUATION_NODE_VIEW_ITEM_H

#include <QQuickItem3D>

namespace presentation
{
    class SituationNodeViewItem: public QQuickItem3D
    {
        Q_OBJECT

        Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)

    public:
        explicit SituationNodeViewItem(QQuickItem* parent = nullptr);
        virtual ~SituationNodeViewItem() override;

        QString path() const;

    public slots:
        void setPath(const QString& path);
        void reload();

    signals:
        void pathChanged(QString path);

    protected:
        virtual void draw(QGLPainter* painter);

    private:
        class SituationNodeViewItemPrivate;
        SituationNodeViewItemPrivate* d;
    };
}
#endif // SITUATION_NODE_VIEW_ITEM_H
