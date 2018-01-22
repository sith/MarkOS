//
// Created by Oleksandra Baukh on 1/21/18.
//

#include "CycleTest.h"
#include "MockCycleListener.h"

using ::testing::Return;
using ::testing::Exactly;

TEST(CycleTest, cycleTest) {
    MockCycleListener cycleListener;
    EXPECT_CALL(cycleListener, onEvent(1)).Times(Exactly(1));
    EXPECT_CALL(cycleListener, onEvent(2)).Times(Exactly(1));

    Cycle cycle = *new Cycle;
    cycle.getListeners()->add(&cycleListener);
    cycle.next();
    ASSERT_EQ(cycle.getCycle(), 1);
    cycle.next();
    ASSERT_EQ(cycle.getCycle(), 2);
}

