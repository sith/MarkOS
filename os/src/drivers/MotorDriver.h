//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_MOTORDRIVER_H
#define MARKOS_MOTORDRIVER_H

enum class Direction {
    NONE = 0,
    FORWARD = 1,
    BACKWARD = 2,
    TURN_LEFT = 3,
    TURN_RIGHT = 4
};

enum class Speed {
    NONE,
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED
};

class MotorDriver {
protected:
    Direction currentDirection = Direction::NONE;
    Speed currentSpeed = Speed::NONE;

public:
    virtual void execute(Direction direction, Speed speed)= 0;

    virtual void stop()= 0;

    Direction getCurrentDirection() const {
        return currentDirection;
    }

    Speed getCurrentSpeed() const {
        return currentSpeed;
    }
};


#endif //MARKOS_MOTORDRIVER_H
