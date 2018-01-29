//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARK1_TIMERTASK_H
#define MARK1_TIMERTASK_H


#include "TimerListener.h"

class TimerTask {
    long time;
    TimerListener *listener;
public:
    TimerListener *getListener() const;

public:
    TimerTask(long time, TimerListener *listener);

    bool isDone(long currentTime);
};


#endif //MARK1_TIMERTASK_H
