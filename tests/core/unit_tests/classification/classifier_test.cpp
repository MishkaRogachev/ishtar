#include "classifier_test.h"

#include <QDebug>

#include "classifier.h"

using namespace classification;

void ClassifierTest::variantConversion()
{
    Classifier classifier1(QPen(Qt::red));

    QLinearGradient gradient;
    gradient.setColorAt(0, Qt::green);
    gradient.setColorAt(1, Qt::blue);

    QBrush brush(gradient);
    brush.setColor(Qt::yellow);

    classifier1.setBrush(brush);

    Classifier classifier2 = Classifier::fromVariantMap(
                                 classifier1.toVariantMap());

    qDebug() << classifier1.brush() << classifier1.pen();
    qDebug() << classifier2.brush() << classifier2.pen();

    QVERIFY(classifier1 == classifier2);
}
