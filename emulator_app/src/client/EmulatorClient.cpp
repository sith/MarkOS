#include <iostream>
#include <List.h>
#include <LinkedList.h>
#include <controller/EmulatorController.h>
#include <logger/StdOutLoggerFactory.h>
#include <environment/Environment.h>
#include "CommandManager.h"

//#include <boost/filesystem.hpp>
//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp>

using namespace std;
//using namespace boost::filesystem;
//using boost::is_any_of;

int main(int argc, char **argv) {
    StdOutLoggerFactory *loggerFactory = new StdOutLoggerFactory;
    Environment::getEnvironment().setLoggerFactory(loggerFactory);
    CommandManager commandManager;

    EmulatorController *controller = new EmulatorController;
    commandManager.registerCommand(controller);
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