//
// Created by Fedorov, Alex on 1/29/18.
//

#include "SystemClock.h"

#include <ctime>


long SystemClock::getTime() {
    time_t *currentTime = nullptr;
    time(currentTime);
    time_t value = *currentTime - *startTime;
    delete currentTime;
    return value;
}

SystemClock::~SystemClock() {
    delete startTime;
}

SystemClock::SystemClock() {
    time(startTime);


}
