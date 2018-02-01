//
// Created by Fedorov, Alex on 1/29/18.
//


#include <logger/StdOutLogger.h>
#include <environment/Environment.h>
#include <clock/SystemClock.h>
#include <iostream>
#include <logger/StdOutLoggerFactory.h>
#include <modes/ModeManager.h>
#include <controller/EmulatorController.h>

ModeManager *modeManager;

void setup() {
    StdOutLoggerFactory *loggerFactory = new StdOutLoggerFactory;
    Environment::getEnvironment().setLoggerFactory(loggerFactory);
    SystemClock *systemClock = new SystemClock;
    Environment::getEnvironment().setClock(systemClock);

    Timer *timer = new Timer(*systemClock);
    Environment::getEnvironment().setTimer(timer);


    EmulatorController *controller = new EmulatorController;
    Environment::getEnvironment().setController(controller);
    Environment::getEnvironment().getCycle().getListeners()->add(controller);

    modeManager = new ModeManager;
    controller->addModeListener(*modeManager);

    loggerFactory->createLogger("Main")->newLine()->logAppend("App is started");
}


void loop() {
    Cycle &cycle = Environment::getEnvironment().getCycle();
    cycle.next();
    modeManager->getCurrentMode().process();
}


int main(int argc, char **argv) {
    setup();

    while (true) {
        loop();
    }

    return 0;
}
