//
// Created by Oleksandra Baukh on 1/10/18.
//

#include "Environment.h"

Environment *Environment::environment;

Environment &Environment::getEnvironment() {
    return *environment;
}

void Environment::setEnvironment(Environment *environment) {
    Environment::environment = environment;
}

void Environment::loop() {
    cycle.next();
    modeManager.getCurrentMode().process();
}

ModeManager &Environment::getModeManager() {
    return modeManager;
}

Cycle &Environment::getCycle() {
    return cycle;
}

Timer &Environment::getTimer() {
    return timer;
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

Environment::Environment(Controller *controller, Random *random, Clock *clock) : controller(controller), random(random),
                                                                                 clock(clock) {
    cycle.getListeners()->add(controller);
    cycle.getListeners()->add(&timer);
    controller->addModeListener(modeManager);
}
