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
    static Environment environment;
protected:
    ModeManager *modeManager;
    Cycle *cycle;
    Timer *timer;

    Controller *controller;
    Random *random;
    Clock *clock;

public:
    ModeManager &getModeManager();

    Cycle &getCycle();

    Timer &getTimer();

    Controller *getController();

    Random *getRandom();

    Clock *getClock();

    static Environment &getEnvironment();

    void setController(Controller *controller);

    void setRandom(Random *random);

    void setClock(Clock *clock);

    void init();

    void loop();
};


#endif //MARKOS_ENVIRONMENT_H
