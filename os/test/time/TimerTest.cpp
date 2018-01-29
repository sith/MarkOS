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
    timer = new Timer(*clock);
    auto environment = Environment::getEnvironment();
    environment.setClock(clock);
    environment.setTimer(timer);
    environment.getCycle().getListeners()->add(timer);
}

TEST_F(TimerTest, addTimer) {

    EXPECT_CALL(*clock, getTime())
            .Times(4)
            .WillOnce(Return(0L))
            .WillOnce(Return(100))
            .WillOnce(Return(500))
            .WillOnce(Return(1000));


    MockTimerListener listener;
    EXPECT_CALL(listener, onEvent()).Times(Exactly(1));

    timer->addTimer(1000, listener);
    Environment::getEnvironment().getCycle().next();
    Environment::getEnvironment().getCycle().next();
    Environment::getEnvironment().getCycle().next();
}

TEST_F(TimerTest, removeTimer) {

    EXPECT_CALL(*clock, getTime())
            .Times(6)
            .WillOnce(Return(0L)) //called when task 1 is created
            .WillOnce(Return(0L)) //called when task 2 is created
            .WillOnce(Return(0L)) //called when task 3 is created
            .WillOnce(Return(100))
            .WillOnce(Return(500))
            .WillOnce(Return(2000));


    MockTimerListener listener1;
    EXPECT_CALL(listener1, onEvent()).Times(Exactly(1));
    MockTimerListener listener2;
    EXPECT_CALL(listener2, onEvent()).Times(Exactly(1));

    timer->addTimer(100, listener1);
    timer->addTimer(600, listener2);
    timer->addTimer(1000, listener1);
    Environment::getEnvironment().getCycle().next();
    timer->removeTasksForListener(listener1);
    Environment::getEnvironment().getCycle().next();
    Environment::getEnvironment().getCycle().next();
}
