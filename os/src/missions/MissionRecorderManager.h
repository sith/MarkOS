//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MISSIONRECORDERMANAGER_H
#define MARKOS_MISSIONRECORDERMANAGER_H


#include <memory/Pointer.h>
#include "MissionRecorder.h"

class MissionRecorderManager {



public:
    Pointer<MissionRecorder> getMissionRecorder(const char *missionName);

};


#endif //MARKOS_MISSIONRECORDERMANAGER_H
