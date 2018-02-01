#include <RemoteCommand.h>

using namespace std;

const string &RemoteCommand::getCommandName() const {
    return commandName;
}

void RemoteCommand::sendCommand() {
    ofstream myfile;
    string path = transportPath + commandName + ".tmp";
    myfile.open(path, std::ios_base::trunc);
    send(myfile);
    myfile.close();
    rename(path.c_str(), (transportPath + commandName).c_str());
}

void RemoteCommand::openStream(ifstream &stream) {
    string path = transportPath + commandName;
    stream.open(path);
}

void RemoteCommand::acknowledgeCommand() {
    remove((transportPath + commandName).c_str());
}


