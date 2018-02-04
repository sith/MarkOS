//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_ENVIRONMENT_H
#define MARKOS_ENVIRONMENT_H


#include <modes/ModeManager.h>
#include "../controller/Controller.h"
#include "../logger/LoggerFactory.h"
#include "../Random.h"
#include "../time/Clock.h"
#include "../cycle/Cycle.h"
#include "../time/Timer.h"

class Environment {
    static Environment *environment;
protected:
    ModeManager modeManager;
    Cycle cycle;
    Timer timer;

    Controller *controller;
    Random *random;
    Clock *clock;

public:

    Environment(Controller *controller, Random *random, Clock *clock);

    ModeManager &getModeManager();

    Cycle &getCycle();

    Timer &getTimer();

    Controller *getController();

    Random *getRandom();

    Clock *getClock();

    static Environment &getEnvironment();

    static void setEnvironment(Environment *environment);

    void loop();
};


#endif //MARKOS_ENVIRONMENT_H
