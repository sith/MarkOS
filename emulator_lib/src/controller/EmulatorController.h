//
// Created by Fedorov, Alex on 1/31/18.
//

#ifndef MARKOS_EMULATORCONTROLLER_H
#define MARKOS_EMULATORCONTROLLER_H


#include <controller/Controller.h>
#include <RemoteCommand.h>
#include <cycle/CycleListener.h>
#include <logger/Logger.h>

using namespace std;

class EmulatorController : public Controller, public RemoteCommand {
    ModeName findModeName(string &modeNameString);

    Logger *logger;

    void send(ofstream &ofstream) override;

public:
    virtual ~EmulatorController();

    EmulatorController();

    Command readControllerCommand() override;

    Command processModeCommand(string &value);

    Command processActionCommand(const string &value);
};


#endif //MARKOS_EMULATORCONTROLLER_H
