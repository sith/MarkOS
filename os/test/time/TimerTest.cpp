//
// Created by Oleksandra Baukh on 1/22/18.
//

#include <environment/Environment.h>
#include "TimerTest.h"
#include "MockTimerListener.h"
#include "MockClock.h"

using ::testing::Return;
using ::testing::Exactly;

void TimerTest::SetUp() {
    clock = new MockClock;
    timer = new Timer(clock);
    auto environment = *new Environment;
    environment.setClock(clock);
    environment.setTimer(timer);
    environment.getCycle().getListeners()->add(timer);
    Environment::setEnvironment(environment);
}

TEST_F(TimerTest, testAddTimer) {

    EXPECT_CALL(*clock, getTime())
            .Times(4)
            .WillOnce(Return(0L))
            .WillOnce(Return(100))
            .WillOnce(Return(500))
            .WillOnce(Return(100));


    MockTimerListener listener;
    EXPECT_CALL(listener, onEvent()).Times(Exactly(1));

    timer->addTimer(1000, listener);
    Environment::getEnvironment().getCycle().next();
    Environment::getEnvironment().getCycle().next();
    Environment::getEnvironment().getCycle().next();
}
