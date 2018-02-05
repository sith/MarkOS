//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_EMULATOROBSTACLESENSOR_H
#define MARKOS_EMULATOROBSTACLESENSOR_H


#include <sensors/ObstacleSensor.h>
#include <RemoteCommand.h>

class EmulatorObstacleSensor : public ObstacleSensor, public RemoteCommand {
public:
    EmulatorObstacleSensor();

    void send(ofstream &ofstream) override;

    Obstacle read() override;

};


#endif //MARKOS_EMULATOROBSTACLESENSOR_H
