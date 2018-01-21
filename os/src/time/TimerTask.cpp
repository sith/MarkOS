//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "TimerTask.h"

TimerTask::TimerTask(long time, TimerListener *listener) : time(time),
                                                          listener(listener) {}

bool TimerTask::isDone(long currentTime) {
    return currentTime >= time;
}

TimerListener *TimerTask::getListener() const {
    return listener;
}
