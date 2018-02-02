//
// Created by Fedorov, Alex on 1/29/18.
//

#include "SystemClock.h"

#include <ctime>
#include <sys/time.h>


long SystemClock::getTime() {
    timeval endTime;
    gettimeofday(&endTime, NULL);
    long diff = toMilliseconds(endTime) - toMilliseconds(startTime);
    return diff;
}

long SystemClock::toMilliseconds(const timeval &time) const {
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}

SystemClock::~SystemClock() {
}

SystemClock::SystemClock() {
    gettimeofday(&startTime, NULL);
}
