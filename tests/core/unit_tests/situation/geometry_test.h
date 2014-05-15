#ifndef GEOMETRY_TEST_H
#define GEOMETRY_TEST_H

#include <QTest>

class GeometryTest: public QObject
{
    Q_OBJECT

private slots:
    void equalType();
    void equalPoints();
    void equalChildren();
};

#endif // GEOMETRY_TEST_H
