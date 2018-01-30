//
// Created by Fedorov, Alex on 1/29/18.
//

#include "SystemClock.h"

#include <ctime>


long SystemClock::getTime() {
    time_t *a;
    time(a);
    time_t vlue = *a;
    delete a;
    return vlue;
}
