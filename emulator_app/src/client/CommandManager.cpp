//
// Created by Fedorov, Alex on 1/31/18.
//

#include "CommandManager.h"

using namespace std;

RemoteCommand *CommandManager::findCommand(string commandName) {
    for (auto &&command : commands) {
        if (commandName == command->getCommandName()) {
            return command;
        }
    }
    return nullptr;
}

void CommandManager::registerCommand(RemoteCommand *command) {
    commands.push_back(command);
}
