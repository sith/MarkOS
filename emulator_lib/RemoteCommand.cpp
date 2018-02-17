#include <RemoteCommand.h>

using namespace std;

const string &RemoteCommand::getCommandName() const {
    return commandName;
}

void RemoteCommand::sendCommand() {
    ofstream myfile;
    auto finalPath = transportPath + commandName;
    auto tmpPath = finalPath + ".tmp";
    myfile.open(tmpPath, std::ios_base::trunc);
    send(myfile);
    myfile.close();
    rename(tmpPath.c_str(), finalPath.c_str());
}

void RemoteCommand::openStream(ifstream &stream) {
    string path = transportPath + commandName;
    stream.open(path);
}

void RemoteCommand::acknowledgeCommand(ifstream &stream) {
    stream.close();
    remove((transportPath + commandName).c_str());
}


