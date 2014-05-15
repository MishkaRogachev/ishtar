#ifndef SITUATION_NODE_TEST_H
#define SITUATION_NODE_TEST_H

#include <QTest>

class NodeTest: public QObject
{
    Q_OBJECT

private slots:
    void copy();
    void equal();
    void equalChildren();

};

#endif //SITUATION_NODE_TEST_H
