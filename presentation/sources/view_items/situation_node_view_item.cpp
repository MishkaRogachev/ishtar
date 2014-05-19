#include "situation_node_view_item.h"

#include "node.h"
#include "node_serializer/json_node_serializer.h"

using namespace presentation;

class SituationNodeViewItem::SituationNodeViewItemPrivate
{
public:
    QString path;
    situation::JSonNodeSerializer serializer;
    situation::NodePtr node;
};

SituationNodeViewItem::SituationNodeViewItem(QQuickItem* parent):
    QQuickItem3D(parent),
    d(new SituationNodeViewItemPrivate())
{

}

SituationNodeViewItem::~SituationNodeViewItem()
{
    delete d;
}

QString SituationNodeViewItem::path() const
{
    return d->path;
}

void SituationNodeViewItem::setPath(const QString& path)
{
    qDebug() << path;
    if (d->path == path) return;

    d->path = path;

    this->reload();
    emit this->pathChanged(path);

    this->update();
}

void SituationNodeViewItem::reload()
{
    d->node = d->serializer.load(d->path);

    if (d->node.isNull()) return;

    qDebug() << d->node->id();

    if (d->node->geometry())
    {
 //       this->setMesh(new QQuickMesh);
    }
}

void SituationNodeViewItem::draw(QGLPainter* painter)
{
    QQuickItem3D::draw(painter);
}
