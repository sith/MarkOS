//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_TIMERTEST_H
#define MARKOS_TIMERTEST_H


#include <gtest/gtest.h>
#include "../../src/time/Timer.h"
#include "MockClock.h"

class TimerTest : public ::testing::Test {
protected:
    void SetUp() override;
    Timer *timer;
    MockClock *clock;
};


#endif //MARKOS_TIMERTEST_H
