#include "i_node_serializer.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

using namespace situation;

bool INodeSerializer::save(const NodePtr& node, const QString& filename) const
{
    QFile file(filename);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out << this->nodeToByteArray(node);
        return true;
    }
    return false;
}

NodePtr INodeSerializer::load(const QString& filename) const
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return this->byteArrayToNode(file.readAll());
    }

    return NodePtr();
}
