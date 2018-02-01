//
// Created by Fedorov, Alex on 1/29/18.
//

#include "SystemClock.h"

#include <ctime>


long SystemClock::getTime() {
    time_t currentTime;
    time(&currentTime);
    time_t value = currentTime - startTime;
    return value;
}

SystemClock::~SystemClock() {
}

SystemClock::SystemClock() {
    time(&startTime);
}
