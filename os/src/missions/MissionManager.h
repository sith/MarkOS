//
// Created by Fedorov, Alex on 2/28/18.
//

#ifndef MARKOS_MISSIONMANAGER_H
#define MARKOS_MISSIONMANAGER_H


#include <memory/Pointer.h>
#include "MissionRecorder.h"

class MissionManager {
public:
    virtual Pointer<MissionRecorder> getLastMission()= 0;

    virtual Pointer<MissionRecorder> newMission()= 0;
};


#endif //MARKOS_MISSIONMANAGER_H
