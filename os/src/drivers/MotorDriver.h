//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_MOTORDRIVER_H
#define MARKOS_MOTORDRIVER_H

#include <collections/List.h>
#include <memory/Pointer.h>
#include <collections/LinkedList.h>

enum class Direction {
    NONE = 0,
    FORWARD = 1,
    BACKWARD = 2,
    TURN_LEFT = 3,
    TURN_RIGHT = 4
};

enum class Speed {
    NONE = 0,
    LOW_SPEED = 1,
    MEDIUM_SPEED = 2,
    HIGH_SPEED = 3
};

class MotorDriverCommandListener {
public:
    virtual void onEvent(Direction direction, Speed speed)= 0;

    virtual void onStop()= 0;
};

class MotorDriver {
    Speed currentSpeed = Speed::NONE;
    Direction currentDirection = Direction::NONE;
    Pointer<List<MotorDriverCommandListener>> listeners{new LinkedList<MotorDriverCommandListener>};
protected:
    virtual void executeInternal(Direction direction, Speed speed)= 0;

    virtual void stopInternal()= 0;

public:
    Speed getCurrentSpeed() const {
        return currentSpeed;
    }

    Direction getCurrentDirection() const {
        return currentDirection;
    }

    void execute(Direction direction, Speed speed) {
        currentSpeed = speed;
        currentDirection = direction;
        executeInternal(direction, speed);
    }

    void stop() {
        currentSpeed = Speed::NONE;
        currentDirection = Direction::NONE;
        stopInternal();
    }
};


#endif //MARKOS_MOTORDRIVER_H
