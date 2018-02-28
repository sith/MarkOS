//
// Created by Oleksandra Baukh on 2/27/18.
//

#ifndef MARKOS_MISSIONRECORDER_H
#define MARKOS_MISSIONRECORDER_H


class MissionRecorder {

public:
    virtual void record()= 0;

    virtual void replay()= 0;

    virtual void stop()= 0;
};


#endif //MARKOS_MISSIONRECORDER_H
