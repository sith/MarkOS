//
// Created by Oleksandra Baukh on 2/28/18.
//

#ifndef MARKOS_EMULATORMISSIONMANAGER_H
#define MARKOS_EMULATORMISSIONMANAGER_H


#include <missions/MissionManager.h>
#include <drivers/MotorDriver.h>
#include <time/TimerListener.h>
#include <string/String.h>
#include <string>

class EmulatorMissionManager : public MissionManager, public MotorDriverCommandListener {

    std::string missionContent;

public:
    void recordMission() override;

    void stopMissionRecording() override;

    void stopMissionReplay() override;

    void recordMission(int8 id) override;

    void replayLastMission() override;

    void replayMission(int8 id) override;

    void onEvent(Direction direction, Speed speed) override;

    void onMotorStop() override;
};


#endif //MARKOS_EMULATORMISSIONMANAGER_H
