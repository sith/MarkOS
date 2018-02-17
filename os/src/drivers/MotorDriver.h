//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARKOS_MOTORDRIVER_H
#define MARKOS_MOTORDRIVER_H

enum Direction {
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT
};

enum Speed {
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED
};

class MotorDriver {
public:
    virtual void execute(Direction direction, Speed speed)= 0;

    virtual void stop()= 0;
};


#endif //MARKOS_MOTORDRIVER_H
