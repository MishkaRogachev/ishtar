#ifndef SITUATION_NODE_TEST_H
#define SITUATION_NODE_TEST_H

#include <QTest>

class NodeTest: public QObject
{
    Q_OBJECT

private slots:
    void equal();
    void copy();
};

#endif //SITUATION_NODE_TEST_H
