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
    controller->addModeListener(*modeManager);
}

MotorDriver *Environment::getMotorDriver() const {
    return motorDriver;
}

void Environment::setMotorDriver(MotorDriver *motorDriver) {
    Environment::motorDriver = motorDriver;
}

