//
// Created by Oleksandra Baukh on 2/4/18.
//

#include <environment/Environment.h>
#include "EmulatorMotorDriver.h"

void EmulatorMotorDriver::execute(Direction direction, Speed speed) {
    logger
            ->newLine()
            ->logAppend("Direction :")
            ->logAppend(EmulatorMotorDriver::direction[static_cast<int>(direction)].c_str())
            ->logAppend(", speed:")
            ->logAppend(EmulatorMotorDriver::speed[static_cast<int>(speed)].c_str());
}

void EmulatorMotorDriver::stop() {
    logger->newLine()->logAppend("Motor is stopped");
}

EmulatorMotorDriver::EmulatorMotorDriver() : logger(LoggerFactory::newLogger("MotorDriver")) {}

EmulatorMotorDriver::~EmulatorMotorDriver() {
    delete logger;
}
