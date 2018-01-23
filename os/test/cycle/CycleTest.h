//
// Created by Oleksandra Baukh on 1/21/18.
//

#ifndef MARKOS_CYCLETEST_H
#define MARKOS_CYCLETEST_H


#include <gtest/gtest.h>

#include "../../src/cycle/Cycle.h"
#include "MockCycleListener.h"

class CycleTest : public ::testing::Test {
protected:
    Cycle cycle;

    void SetUp() {
        cycle = *new Cycle;
    };
};


#endif //MARKOS_CYCLETEST_H
