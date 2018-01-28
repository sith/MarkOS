//
// Created by Oleksandra Baukh on 1/10/18.
//

#include "Environment.h"

Environment Environment::environment;

Environment &Environment::getEnvironment() {
    return environment;
}

void Environment::setController(Controller *controller) {
    Environment::controller = controller;
}

LoggerFactory *Environment::getLoggerFactory() const {
    return loggerFactory;
}

void Environment::setLoggerFactory(LoggerFactory *loggerFactory) {
    Environment::loggerFactory = loggerFactory;
}

Random *Environment::getRandom() const {
    return random;
}

void Environment::setRandom(Random *random) {
    Environment::random = random;
}

Clock *Environment::getClock() const {
    return clock;
}

void Environment::setClock(Clock *clock) {
    Environment::clock = clock;
}

Cycle &Environment::getCycle() {
    return cycle;
}

Environment::Environment() : cycle(*new Cycle) {
}

Timer *Environment::getTimer() const {
    return timer;
}

void Environment::setTimer(Timer *timer) {
    Environment::timer = timer;
}

