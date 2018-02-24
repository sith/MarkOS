//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_TIMEBASEDMISSIONRECORDERTEST_H
#define MARKOS_TIMEBASEDMISSIONRECORDERTEST_H

#include <gtest/gtest.h>
#include <missions/TimeBasedMissionRecorder.h>
#include "../mocks/MockFile.h"
#include "../mocks/MockFileSystem.h"

class TimeBasedMissionRecorderTest : ::testing::Test {
protected:
    TimeBasedMissionRecorder missionRecorder;
    MockFile recorderFile;
    MockFileSystem fileSystem;
private:
    void SetUp() override;

};


#endif //MARKOS_TIMEBASEDMISSIONRECORDERTEST_H
