//
// Created by Fedorov, Alex on 1/31/18.
//

#ifndef MARKOS_COMMANDMANAGER_H
#define MARKOS_COMMANDMANAGER_H


#include <vector>
#include "RemoteCommand.h"

class CommandManager {

    std::vector<RemoteCommand *> commands;

public:
    RemoteCommand *findCommand(std::string commandName);

    void registerCommand(RemoteCommand *command);
};


#endif //MARKOS_COMMANDMANAGER_H
