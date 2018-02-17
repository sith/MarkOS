//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_EMULATORMOTORDRIVER_H
#define MARKOS_EMULATORMOTORDRIVER_H


#include <drivers/MotorDriver.h>
#include <logger/Logger.h>
#include <string>


class EmulatorMotorDriver : public MotorDriver {


    std::string direction[4] = {
            "FORWARD",
            "BACKWARD",
            "TURN_LEFT",
            "TURN_RIGHT"
    };

    std::string speed[3] = {
            "LOW_SPEED",
            "MEDIUM_SPEED",
            "HIGH_SPEED"
    };

    Pointer<Logger> logger;

public:
    EmulatorMotorDriver();

    virtual ~EmulatorMotorDriver();

    void execute(Direction direction, Speed speed) override;

    void stop() override;
};


#endif //MARKOS_EMULATORMOTORDRIVER_H
