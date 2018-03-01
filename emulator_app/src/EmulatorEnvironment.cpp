//
// Created by Oleksandra Baukh on 2/25/18.
//

#include "EmulatorEnvironment.h"

Controller &EmulatorEnvironment::getController() {
    return controller;
}

Clock &EmulatorEnvironment::getClock() {
    return clock;
}

MotorDriver &EmulatorEnvironment::getMotorDriver() {
    return motorDriver;
}

ObstacleSensor &EmulatorEnvironment::getObstacleSensor() {
    return obstacleSensor;
}

FileSystem &EmulatorEnvironment::getFileSystem() {
    return fileSystem;
}

MemoryMonitor &EmulatorEnvironment::getMemoryMonitor() {
    return memoryMonitor;
}

Timer &EmulatorEnvironment::getTimer() {
    return timer;
}

EmulatorEnvironment &EmulatorEnvironment::operator=(const EmulatorEnvironment &environment) {
    return *this;
}

ModeManager &EmulatorEnvironment::getModeManager() {
    return modeManager;
}

Cycle &EmulatorEnvironment::getCycle() {
    return cycle;
}

MissionManager &EmulatorEnvironment::getMissionManager() {
    return missionManager;
}
