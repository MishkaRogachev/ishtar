#include "classifier_test.h"

#include "classifier.h"

using namespace classification;

void ClassifierTest::variantConversion()
{
    Classifier classifier1;

    Classifier classifier2 = Classifier::fromVariantMap(
                                 classifier1.toVariantMap());

    QVERIFY(classifier1 == classifier2);
}
