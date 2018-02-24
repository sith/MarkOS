//
// Created by Fedorov, Alex on 2/23/18.
//

#include "TimeBasedMissionRecorderTest.h"
#include <gtest/gtest.h>

using ::testing::Mock;
using ::testing::AnyNumber;
using ::testing::_;


void TimeBasedMissionRecorderTest::SetUp() {
    Mock::VerifyAndClearExpectations(&recorderFile);
    Mock::VerifyAndClearExpectations(&fileSystem);

    missionRecorder = {"testMission"};

    EXPECT_CALL(fileSystem, openFile("/missions/testMission.DAT")).Times(AnyNumber());

}


TEST_F(TimeBasedMissionRecorderTest, recordTest) {


}
