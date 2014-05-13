#include "situation_object.h"

using namespace situation;

class Node::NodePrivate
{
public:
    Excode excode;
    common::PointPtrList points;
};

Node::Node(Excode excode, const common::PointPtrList& points):
    d(new NodePrivate())
{
    d->excode = excode;
    d->points = points;
}

Node::~Node()
{
    delete d;
}

void Node::setExcode(Excode excode)
{
    d->excode = excode;
}

Excode Node::excode() const
{
    return d->excode;
}

common::PointPtrList Node::points() const
{
    return d->points;
}

common::PointPtrList& Node::rPoints() const
{
    return d->points;
}


