//
// Created by Oleksandra Baukh on 1/29/18.
//

#ifndef MARKOS_RemoteCommand_H
#define MARKOS_RemoteCommand_H

#include <fstream>

using namespace std;

class RemoteCommand {
    string commandName;
    string transportPath = "/tmp/emulator/";
public:

    RemoteCommand(const string &commandName) : commandName(commandName) {}

    const std::string &getCommandName() const;

    void sendCommand();

    void openStream(ifstream &stream);

    void acknowledgeCommand(ifstream &stream);

    virtual void send(ofstream &ofstream)= 0;
};

#endif //MARKOS_COMMAND_H
