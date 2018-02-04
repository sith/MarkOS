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


void setup() {

    LoggerFactory::setLoggerFactory(new StdOutLoggerFactory);

    Environment *environment = new Environment(new EmulatorController, nullptr, new SystemClock);
    Environment::setEnvironment(environment);


    LoggerFactory::newLogger("Main")->newLine()->logAppend("App is started");
}


void loop() {
    Environment::getEnvironment().loop();
}

int main(int argc, char **argv) {
    setup();

    while (true) {
        loop();
    }

    return 0;
}
