//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_FILESYSTEMMISSIONMANAGER_H
#define MARKOS_FILESYSTEMMISSIONMANAGER_H


#include <filesystem/FileSystem.h>
#include <Random.h>
#include "MissionManager.h"
#include "../../test/missions/MissionIdGenerator.h"

class FileSystemMissionManager : public MissionManager {
    FileSystem *fileSystem;
    MissionIdGenerator *missionIdGenerator;
public:
    FileSystemMissionManager(FileSystem &fileSystem, MissionIdGenerator &missionIdGenerator);

    Pointer<MissionRecorder> getLastMission() override;

    Pointer<MissionRecorder> newMission() override;

};


#endif //MARKOS_FILESYSTEMMISSIONMANAGER_H
