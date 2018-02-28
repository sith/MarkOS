//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_FILESYSTEMMISSIONMANAGERTEST_H
#define MARKOS_FILESYSTEMMISSIONMANAGERTEST_H


#include <gtest/gtest.h>
#include <missions/FileSystemMissionManager.h>
#include "../mocks/MockFileSystem.h"
#include "../mocks/MockMissionIdGenerator.h"

class FileSystemMissionManagerTest : public ::testing::Test {
protected:
    FileSystemMissionManagerTest() {}

    MockFileSystem fileSystem;
    MockMissionIdGenerator missionIdGenerator;
    FileSystemMissionManager missionManager{fileSystem, missionIdGenerator};

};


#endif //MARKOS_FILESYSTEMMISSIONMANAGERTEST_H
