//
// Created by Oleksandra Baukh on 2/28/18.
//

#include <environment/Environment.h>
#include <iostream>
#include "EmulatorMissionManager.h"

void EmulatorMissionManager::recordMission() {
    recordMission(1);
}

void EmulatorMissionManager::recordMission(int8 id) {
    Environment::getEnvironment().getMotorDriver().addListener(this);
    missionContent.append("Recording started\n");
}

void EmulatorMissionManager::stopMissionRecording() {
    Environment::getEnvironment().getMotorDriver().removeListener(this);
    missionContent.append("Recording finished\n");
}

void EmulatorMissionManager::replayLastMission() {
    replayMission(1);
}

void EmulatorMissionManager::replayMission(int8 id) {
    std::cout << missionContent;
}

void EmulatorMissionManager::stopMissionReplay() {
    missionContent.append("Replaying finished\n");
}

void EmulatorMissionManager::onEvent(Direction direction, Speed speed) {
    missionContent += "Direction ";
    missionContent += std::to_string(static_cast<int>(direction));
    missionContent += " speed ";
    missionContent += std::to_string(static_cast<int>(speed));
    missionContent += " time ";
    missionContent += std::to_string(Environment::getEnvironment().getClock().getTime());
    missionContent += "\n\n";
}

void EmulatorMissionManager::onMotorStop() {
    missionContent += "Motor stopped at time ";
    missionContent += std::to_string(Environment::getEnvironment().getClock().getTime());
    missionContent += "\n\n";
}
