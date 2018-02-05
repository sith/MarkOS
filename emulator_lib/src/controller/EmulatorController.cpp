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
        command = processModeCommand(value);
    } else if (type == "action") {
        command = processActionCommand(value);
    }

    stream.close();
    acknowledgeCommand();
    return command;
}

Command EmulatorController::processModeCommand(string &value) {
    Command command;
    if (value == "cancel") {
        command = Command::STOP_MODE;
    } else {
        ModeName modeName = findModeName(value);
        Controller::modeName = modeName;
        command = Command::SELECT_MODE;
    }
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

Command EmulatorController::processActionCommand(const string &value) {
    if (value == "FORWARD") {
        return Command::FORWARD;
    }
    if (value == "BACKWARD") {
        return Command::BACKWARD;
    }
    if (value == "STOP") {
        return Command::STOP;
    }
    if (value == "LEFT") {
        return Command::LEFT;
    }
    if (value == "RIGHT") {
        return Command::RIGHT;
    }
    return Command::NONE;
}
