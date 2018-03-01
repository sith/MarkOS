//
// Created by Oleksandra Baukh on 2/27/18.
//

#ifndef MARKOS_MISSIONRECORDER_H
#define MARKOS_MISSIONRECORDER_H

#include "types.h"

class MissionRecorder {
    uint8 id;
public:
    MissionRecorder(uint8 id);

    virtual ~MissionRecorder();

public:
    virtual void record()= 0;

    virtual void replay()= 0;

    virtual void stopRecord()= 0;

    virtual void stopReplay()= 0;

    uint8 getId() const;
};


#endif //MARKOS_MISSIONRECORDER_H
