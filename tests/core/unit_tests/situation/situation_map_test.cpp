#include "situation_map_test.h"

#include "situation_map.h"

using namespace situation;

void SituationMapTest::testCopyMoveDestruction()
{
    SituationMapPtr mapPtr1(new SituationMap());
    SituationMapPtr mapPtr2(mapPtr1);

    QVERIFY(mapPtr1.data() == mapPtr2.data());
}
