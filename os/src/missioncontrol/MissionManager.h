//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_MISSIONFACTORY_H
#define MARKOS_MISSIONFACTORY_H

#include <memory/Pointer.h>
#include "Mission.h"

class MissionManager {
public:
    virtual Pointer<Mission> createNewMission()= 0;
    virtual Pointer<Mission> getLastMission()= 0;

    void init();
};

#endif //MARKOS_MISSIONFACTORY_H
