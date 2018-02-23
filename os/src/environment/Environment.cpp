//
// Created by Oleksandra Baukh on 1/10/18.
//

#include "Environment.h"

Environment Environment::environment;

Environment &Environment::getEnvironment() {
    return environment;
}

void Environment::loop() {
    cycle->next();
    modeManager->getCurrentMode().process();
}

ModeManager &Environment::getModeManager() {
    return *modeManager;
}

Cycle &Environment::getCycle() {
    return *cycle;
}

Timer &Environment::getTimer() {
    return *timer;
}

Controller *Environment::getController() {
    return controller;
}

Random *Environment::getRandom() {
    return random;
}

Clock *Environment::getClock() {
    return clock;
}

void Environment::setController(Controller *controller) {
    Environment::controller = controller;
}

void Environment::setRandom(Random *random) {
    Environment::random = random;
}

void Environment::setClock(Clock *clock) {
    Environment::clock = clock;
}

void Environment::init() {
    modeManager = new ModeManager;
    cycle = new Cycle;
    timer = new Timer;

    cycle->getListeners()->add(controller);
    cycle->getListeners()->add(timer);
    cycle->getListeners()->add(obstacleSensor);

    controller->addModeListener(*modeManager);

    missionManager->init();
}

MotorDriver *Environment::getMotorDriver() const {
    return motorDriver;
}

void Environment::setMotorDriver(MotorDriver *motorDriver) {
    Environment::motorDriver = motorDriver;
}

ObstacleSensor *Environment::getObstacleSensor() const {
    return obstacleSensor;
}

void Environment::setObstacleSensor(ObstacleSensor *obstacleSensor) {
    Environment::obstacleSensor = obstacleSensor;
}

FileSystem *Environment::getFileSystem() const {
    return fileSystem;
}

void Environment::setFileSystem(FileSystem *fileSystem) {
    Environment::fileSystem = fileSystem;
}

MissionManager *Environment::getMissionManager() const {
    return missionManager;
}

void Environment::setMissionManager(MissionManager *missionManager) {
    Environment::missionManager = missionManager;
}

