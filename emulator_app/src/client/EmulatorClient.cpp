#include <iostream>
#include <collections/List.h>
#include <collections/LinkedList.h>
#include <controller/EmulatorController.h>
#include <logger/StdOutLoggerFactory.h>
#include <environment/Environment.h>
#include <sensors/ObstacleSensor.h>
#include <sensors/EmulatorObstacleSensor.h>
#include "CommandManager.h"

//#include <boost/filesystem.hpp>
//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp>

using namespace std;
//using namespace boost::filesystem;
//using boost::is_any_of;

int main(int argc, char **argv) {
    LoggerFactory::setLoggerFactory(new StdOutLoggerFactory);
    CommandManager commandManager;

    commandManager.registerCommand(new EmulatorController);
    commandManager.registerCommand(new EmulatorObstacleSensor);
    
    string command;
    do {
        cin >> command;
        RemoteCommand *findCommand = commandManager.findCommand(command);
        if (findCommand != nullptr) {
            cout << "Send command: " << command << endl;
            findCommand->sendCommand();
        } else {
            cout << "Unsupported command: " << command << endl;
        }
    } while (command != "stop");

    return 0;
}