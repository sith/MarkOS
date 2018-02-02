//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_ENVIRONMENT_H
#define MARKOS_ENVIRONMENT_H


#include "../controller/Controller.h"
#include "../logger/LoggerFactory.h"
#include "../Random.h"
#include "../time/Clock.h"
#include "../cycle/Cycle.h"
#include "../time/Timer.h"

class Environment {
    static Environment environment;
    Controller *controller;
    LoggerFactory *loggerFactory;
    Random *random;
    Clock *clock;
    Timer *timer;
    Cycle cycle;
public:
    Clock *getClock() const;

    void setClock(Clock *clock);

    LoggerFactory *getLoggerFactory() const;

    void setLoggerFactory(LoggerFactory *loggerFactory);

    static Environment &getEnvironment();

    void setController(Controller *controller);

    Random *getRandom() const;

    void setRandom(Random *random);

    Cycle &getCycle();

    Timer *getTimer() const;

    void setTimer(Timer *timer);

};


#endif //MARKOS_ENVIRONMENT_H
