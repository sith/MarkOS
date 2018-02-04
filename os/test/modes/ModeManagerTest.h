//
// Created by Fedorov, Alex on 1/28/18.
//

#ifndef MARKOS_MODEMANAGERTEST_H
#define MARKOS_MODEMANAGERTEST_H


#include <gtest/gtest.h>
#include <modes/ModeManager.h>
#include <environment/Environment.h>
#include <logger/StdOutLoggerFactory.h>

class ModeManagerTest : public ::testing::Test {
protected:
    ModeManager *modeManager;
    StdOutLoggerFactory factory;

    void SetUp() override {
        LoggerFactory::setLoggerFactory(&factory);
        modeManager = new ModeManager;
    }

    void TearDown() override {
        delete modeManager;
        modeManager = nullptr;
    }
};


#endif //MARKOS_MODEMANAGERTEST_H
