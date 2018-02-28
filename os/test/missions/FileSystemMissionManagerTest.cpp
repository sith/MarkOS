//
// Created by Fedorov, Alex on 2/28/18.
//

#include <constants.h>
#include "FileSystemMissionManagerTest.h"

using ::testing::Return;
using ::testing::Exactly;

const char *missionsFolderPath = "/missions";

TEST_F(FileSystemMissionManagerTest, prepareDirectory) {
    MockFileSystem mockFileSystem{};
    EXPECT_CALL(mockFileSystem, createDirectory(missionsFolderPath)).Times(Exactly(1));
    FileSystemMissionManager someManager{mockFileSystem}(<#initializer#>, nullptr);
}


TEST_F(FileSystemMissionManagerTest, openMissionFile) {

    FAIL();

//    missionManager.newMission();

}
