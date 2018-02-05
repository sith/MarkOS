//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_SUPERVISEDMODETEST_H
#define MARKOS_SUPERVISEDMODETEST_H


#include <gtest/gtest.h>
#include <modes/supervised/SupervisedMode.h>
#include "../../mocks/MockMotorDriver.h"
#include "../../mocks/MockController.h"

class SupervisedModeTest : public testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;

    SupervisedMode *supervisedMode;
    MockMotorDriver mockMotorDriver;
    MockController mockController;

};


#endif //MARKOS_SUPERVISEDMODETEST_H
