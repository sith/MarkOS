//
// Created by Oleksandra Baukh on 2/17/18.
//

#include <environment/Environment.h>
#include "FreeRunMode.h"

FreeRunMode::FreeRunMode() : Mode(ModeName::FREE_RUN), motorDriver(Environment::getEnvironment().getMotorDriver()),
                             logger{LoggerFactory::newLogger("FreeRunMode")} {}

FreeRunMode::~FreeRunMode() {}

const void FreeRunMode::process() {
    currentState->execute();
}

void FreeRunMode::init() {
    currentState = &noopState;
    Environment::getEnvironment().getObstacleSensor()->addListener(this);
    motorDriver->execute(Direction::FORWARD, Speed::MEDIUM_SPEED);
}

void FreeRunMode::stop() {
    motorDriver->stop();
    currentState->stop();
    Environment::getEnvironment().getObstacleSensor()->removeListener(this);
}

void FreeRunMode::onEvent(const Obstacle &obstacle) {
    if (obstacle.left) {
        motorDriver->execute(Direction::TURN_RIGHT, Speed::LOW_SPEED);
    } else if (obstacle.right) {
        motorDriver->execute(Direction::TURN_LEFT, Speed::LOW_SPEED);
    } else if (obstacle.forward) {
        motorDriver->execute(Direction::TURN_RIGHT, Speed::LOW_SPEED);
    } else {
        motorDriver->execute(Direction::FORWARD, Speed::MEDIUM_SPEED);
    }
}
