#include <iostream>
#include "EmulatorObstacleSensor.h"

Obstacle EmulatorObstacleSensor::read() {
    ifstream stream;
    openStream(stream);

    Obstacle obstacle{false, false, false};

    if (stream) {
        string obstacleString;
        do {
            stream >> obstacleString;

            if (obstacleString == "left") {
                obstacle.left = true;
            }
            if (obstacleString == "right") {
                obstacle.right = true;
            }
            if (obstacleString == "forward") {
                obstacle.forward = true;
            }
        } while (obstacleString != "end");
        acknowledgeCommand(stream);
    }

    return obstacle;
}

void EmulatorObstacleSensor::send(ofstream &ofstream) {
    string obstacle;
    do {
        std::cin >> obstacle;
        ofstream << obstacle << " ";
    } while (obstacle != "end");
}

EmulatorObstacleSensor::EmulatorObstacleSensor() : RemoteCommand("obstacle") {}
