//
// Created by Fedorov, Alex on 1/31/18.
//

#include <iostream>
#include <environment/Environment.h>
#include "EmulatorController.h"

using namespace std;

Command EmulatorController::readControllerCommand() {
    ifstream stream;

    openStream(stream);

    if (!stream) {
        return Command::NONE;
    }

    string type;
    string value;
    stream >> type >> value;

    Command command = Command::NONE;
    if (type == "mode") {
        if (value == "cancel") {
            command = Command::STOP_MODE;
        } else {
            ModeName modeName = findModeName(value);
            Controller::modeName = modeName;
            command = Command::SELECT_MODE;
        }
    }
    stream.close();
    acknowledgeCommand();
    return command;
}

EmulatorController::EmulatorController() : RemoteCommand("controller"),
                                           logger(LoggerFactory::newLogger("Controller")) {}

void EmulatorController::send(ofstream &ofstream) {
    string type;
    string value;
    cin >> type >> value;
    ofstream << type << " " << value;
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

EmulatorController::~EmulatorController() {
    delete logger;
}
