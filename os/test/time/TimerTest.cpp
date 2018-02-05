//
// Created by Oleksandra Baukh on 1/22/18.
//

#include <logger/StdOutLoggerFactory.h>
#include <cycle/Cycle.h>
#include <time/Timer.h>
#include "TimerTest.h"
#include "MockTimerListener.h"
#include "../mocks/MockClock.h"
#include "../mocks/MockController.h"
#include "../mocks/MockRandom.h"

using ::testing::Return;
using ::testing::Exactly;

void TimerTest::SetUp() {
    LoggerFactory::setLoggerFactory(&loggerFactory);
    cycle = new Cycle;
    clock = new MockClock;
    timer = new Timer(clock);

    cycle->getListeners()->add(timer);
}

void TimerTest::TearDown() {
    Test::TearDown();
    delete timer;
    delete clock;
    delete cycle;
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
    cycle->next();
    cycle->next();
    cycle->next();
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
    cycle->next();
    timer->removeTasksForListener(listener1);
    cycle->next();
    cycle->next();
}
