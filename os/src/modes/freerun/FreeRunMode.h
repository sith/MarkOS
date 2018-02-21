//
// Created by Oleksandra Baukh on 2/17/18.
//

#ifndef MARKOS_FREERUNMODE_H
#define MARKOS_FREERUNMODE_H


#include <modes/Mode.h>
#include <sensors/ObstacleSensor.h>
#include <drivers/MotorDriver.h>
#include <state/State.h>
#include <state/standard/NoopState.h>

class FreeRunMode : public Mode, ObstacleListener {
    MotorDriver *motorDriver;

    Logger* logger;
    State *currentState;
    NoopState noopState;
public:
    FreeRunMode();

    ~FreeRunMode() override;

private:
    void onEvent(Obstacle obstacle) override;

public:
    const void process() override;

    void init() override;

    void stop() override;
};


#endif //MARKOS_FREERUNMODE_H
