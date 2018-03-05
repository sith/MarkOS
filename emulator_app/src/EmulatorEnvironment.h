//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_EMULATORENVIRONMENT_H
#define MARKOS_EMULATORENVIRONMENT_H


#include <environment/Environment.h>
#include <memory/OSMemoryMonitor.h>
#include <controller/EmulatorController.h>
#include <sensors/EmulatorObstacleSensor.h>
#include <drivers/EmulatorMotorDriver.h>
#include <clock/SystemClock.h>
#include <filesystem/OSFileSystem.h>
#include <missions/EmulatorMissionManager.h>
#include <missions/InMemoryMissionManager.h>

class EmulatorEnvironment : public Environment {
    ModeManager modeManager;
    Cycle cycle;
    OSMemoryMonitor memoryMonitor;
    EmulatorController controller;
    EmulatorMotorDriver motorDriver;
    EmulatorObstacleSensor obstacleSensor;
    SystemClock clock;
    OSFileSystem fileSystem;
    Timer timer{&clock};
    InMemoryMissionManager missionManager{motorDriver, timer, clock};
public:
    MissionManager &getMissionManager() override;

    ModeManager &getModeManager() override;

    Cycle &getCycle() override;

    EmulatorEnvironment &operator=(const EmulatorEnvironment &environment);

    Controller &getController() override;

    Clock &getClock() override;

    MotorDriver &getMotorDriver() override;

    ObstacleSensor &getObstacleSensor() override;

    mark_os::filesystem::FileSystem &getFileSystem() override;

    MemoryMonitor &getMemoryMonitor() override;

    Timer &getTimer() override;
};


#endif //MARKOS_EMULATORENVIRONMENT_H
