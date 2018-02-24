//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_EMULATORMOTORDRIVER_H
#define MARKOS_EMULATORMOTORDRIVER_H


#include <drivers/MotorDriver.h>
#include <logger/Logger.h>
#include <string>


class EmulatorMotorDriver : public MotorDriver {
    std::string direction[5] = {
            "NONE",
            "FORWARD",
            "BACKWARD",
            "TURN_LEFT",
            "TURN_RIGHT"
    };

    std::string speed[4] = {
            "NONE",
            "LOW_SPEED",
            "MEDIUM_SPEED",
            "HIGH_SPEED"
    };

    Logger *logger;

public:
    EmulatorMotorDriver();

    virtual ~EmulatorMotorDriver();

protected:
    void executeInternal(Direction direction, Speed speed) override;

    void stopInternal() override;
};


#endif //MARKOS_EMULATORMOTORDRIVER_H
