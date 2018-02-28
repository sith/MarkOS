//
// Created by Fedorov, Alex on 1/29/18.
//


#include <logger/StdOutLogger.h>
#include <environment/Environment.h>
#include <clock/SystemClock.h>
#include <logger/StdOutLoggerFactory.h>
#include <controller/EmulatorController.h>
#include <drivers/EmulatorMotorDriver.h>
#include <sensors/EmulatorObstacleSensor.h>
#include <memory/OSMemoryMonitor.h>
#include "EmulatorEnvironment.h"

void setup() {
    LoggerFactory::setLoggerFactory(new StdOutLoggerFactory);
    Environment::setEnvironment(*new EmulatorEnvironment{});
    Environment::getEnvironment().init();
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
