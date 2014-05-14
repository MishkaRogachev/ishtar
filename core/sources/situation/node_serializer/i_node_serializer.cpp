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
     }
}

NodePtr INodeSerializer::load(const QString& name) const
{
    QFile file(name);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return NodePtr();

    return this->fromByteArray(file.readAll());
}
