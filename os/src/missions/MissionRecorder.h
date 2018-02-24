//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MISSION_H
#define MARKOS_MISSION_H

#include <filesystem/File.h>
#include <memory/Pointer.h>

class MissionRecorder {
    const char* missionName;
public:

    MissionRecorder(const char *missionName) : missionName(missionName) {}

    virtual ~MissionRecorder() {
    }

private:
    virtual void record()= 0;

    virtual void stop()= 0;

    virtual void replay()= 0;
};

#endif //MARKOS_MISSION_H
