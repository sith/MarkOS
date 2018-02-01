//
// Created by Fedorov, Alex on 1/31/18.
//

#ifndef MARKOS_EMULATORCONTROLLER_H
#define MARKOS_EMULATORCONTROLLER_H


#include <controller/Controller.h>
#include <RemoteCommand.h>
#include <cycle/CycleListener.h>
#include <logger/Logger.h>

class EmulatorController : public Controller, public RemoteCommand, public CycleListener {
    ModeName findModeName(string &modeNameString);

    Logger *logger;

    void send(ofstream &ofstream) override;

public:
    virtual ~EmulatorController();

    void onEvent(unsigned long cycleNumber) override;

    EmulatorController();

    void readControllerCommand() override;
};


#endif //MARKOS_EMULATORCONTROLLER_H
