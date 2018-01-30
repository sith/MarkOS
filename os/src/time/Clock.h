//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_CLOCK_H
#define MARK1_CLOCK_H

class Clock {
public:
    virtual ~Clock() {}

    virtual long getTime()= 0;
};

#endif //MARK1_CLOCK_H
