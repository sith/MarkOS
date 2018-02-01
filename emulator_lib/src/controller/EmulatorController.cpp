//
// Created by Fedorov, Alex on 1/31/18.
//

#include <iostream>
#include <environment/Environment.h>
#include "EmulatorController.h"

using namespace std;

void EmulatorController::readControllerCommand() {
    ifstream stream;

    openStream(stream);

    if (!stream) {
        return;
    }

    string modeNameString;
    stream >> modeNameString;
    ModeName modeName = findModeName(modeNameString);
    modeListener->onModeChange(modeName);
    stream.close();
    acknowledgeCommand();
}

EmulatorController::EmulatorController() : RemoteCommand("controller"),
                                           logger(Environment::getEnvironment()
                                                          .getLoggerFactory()->createLogger("Controller")) {}

void EmulatorController::send(ofstream &ofstream) {
    string command;
    cin >> command;
    ofstream << command;
}

ModeName EmulatorController::findModeName(string &modeNameString) {
    if (modeNameString == "SUPERVISED") {
        return SUPERVISED;
    }
    if (modeNameString == "FREE_RUN") {
        return FREE_RUN;
    }
    if (modeNameString == "CALIBRATION") {
        return CALIBRATION;
    }
    if (modeNameString == "EXPLORER") {
        return FIXED_ROUTE;
    }
    if (modeNameString == "EXPLORER") {
        return EXPLORER;
    }
    if (modeNameString == "TEST") {
        return TEST;
    }
    return NONE;
}

void EmulatorController::onEvent(unsigned long cycleNumber) {
    readControllerCommand();
}

EmulatorController::~EmulatorController() {
    delete logger;
}
