#include "i_node_serializer.h"

#include <QFile>
#include <QTextStream>

using namespace situation;

INodeSerializer::INodeSerializer()
{}

bool INodeSerializer::save(const NodePtr& node, const QString& name) const
{
    QFile file(name);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&file);
        out << this->toByteArray(node);
        return true;
    }
    return false;
}

NodePtr INodeSerializer::load(const QString& name) const
{
    QFile file(name);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QByteArray data;
        in >> data;
        return this->fromByteArray(data);
    }

    return NodePtr();


}
