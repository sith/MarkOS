//
// Created by Oleksandra Baukh on 1/17/18.
//


#include "Controller.h"
#include "../modes/ModeListener.h"

void Controller::addModeListener(ModeListener &ml) {
    modeListener = &ml;
}

Controller::~Controller() {
    delete commandListeners;
}

void Controller::onEvent(unsigned long cycleNumber) {
    Command command = readControllerCommand();
    switch (command) {
        case Command::NONE:
            break;
        case Command::FORWARD:
            notifyOnCommand(Command::FORWARD);
            break;
        case Command::LEFT:
            notifyOnCommand(Command::LEFT);
            break;
        case Command::RIGHT:
            notifyOnCommand(Command::RIGHT);
            break;
        case Command::BACKWARD:
            notifyOnCommand(Command::BACKWARD);
            break;
        case Command::STOP:
            notifyOnCommand(Command::STOP);
            break;
        case Command::STOP_MODE:
            modeListener->onModeChange(NONE);
            break;
        case Command::SELECT_MODE:
            modeListener->onModeChange(getModeName());
            break;
    }
}

ModeName Controller::getModeName() const {
    return modeName;
}

Controller::Controller() {}

// TODO unify listeners
void Controller::addListener(ControllerCommandListener &controllerCommandListener) {
    commandListeners->add(&controllerCommandListener);
}

void Controller::removeListener(ControllerCommandListener &controllerCommandListener) {
    commandListeners->removeByPointer(&controllerCommandListener);
}

void Controller::notifyOnCommand(Command command) {
    Iterator<ControllerCommandListener> *iterator = commandListeners->iterator();
    while (iterator->hasNext()) {
        iterator->next()->onEvent(command);
    }
    delete iterator;
}

List<ControllerCommandListener> *Controller::getCommandListeners() const {
    return commandListeners;
}
