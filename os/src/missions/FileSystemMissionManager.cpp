//
// Created by Fedorov, Alex on 2/28/18.
//

#include <constants.h>
#include "FileSystemMissionManager.h"

FileSystemMissionManager::FileSystemMissionManager(FileSystem &fileSystem, MissionIdGenerator &missionIdGenerator)
        : fileSystem(&fileSystem), missionIdGenerator(&missionIdGenerator) {
    FileSystemMissionManager::fileSystem->createDirectory(missionsFolderPath);
}

Pointer<MissionRecorder> FileSystemMissionManager::getLastMission() {
    return Pointer<MissionRecorder>(nullptr);
}

Pointer<MissionRecorder> FileSystemMissionManager::newMission() {
    return Pointer<MissionRecorder>(nullptr);
}

