//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_TESTMODETEST_H
#define MARKOS_TESTMODETEST_H

#include <gtest/gtest.h>
#include "../../../src/modes/test/TestMode.h"

class TestModeTest : public ::testing::Test {
protected:
    TestMode *testMode;

    void SetUp() {
        testMode = new TestMode;
    };

};


#endif //MARKOS_TESTMODETEST_H
