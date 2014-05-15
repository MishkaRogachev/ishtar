#include "bounding_box_test.h"

#include "bounding_box.h"

using namespace situation;

void BoundingBoxTest::equal()
{
    BoundingBox bbox1(0.345, -342.341, 24.13302, 345004.345, 4.45, 5000.001);
    BoundingBox bbox2(0.345, -342.341, 24.13302, 345004.345, 4.45, 5000.001);

    QVERIFY(bbox1 == bbox2);
}
