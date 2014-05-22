#ifndef BOUNDING_BOX_TEST_H
#define BOUNDING_BOX_TEST_H

#include <QTest>

class BoundingBoxTest: public QObject
{
    Q_OBJECT

private slots:
    void equal();
};

#endif // BOUNDING_BOX_TEST_H
