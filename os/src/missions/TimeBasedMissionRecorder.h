//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_TIMEBASEDMISSIONRECORDER_H
#define MARKOS_TIMEBASEDMISSIONRECORDER_H


#include "MissionRecorder.h"

class TimeBasedMissionRecorder : public MissionRecorder{
public:

private:
public:
    TimeBasedMissionRecorder(const char *missionName);

private:
    void record() override;

    void stop() override;

    void replay() override;
};


#endif //MARKOS_TIMEBASEDMISSIONRECORDER_H
