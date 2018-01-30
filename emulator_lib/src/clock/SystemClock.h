//
// Created by Fedorov, Alex on 1/29/18.
//

#ifndef MARKOS_SYSTEMCLOCK_H
#define MARKOS_SYSTEMCLOCK_H


#include <time/Clock.h>

class SystemClock : public Clock{
public:
    long getTime() override;
};


#endif //MARKOS_SYSTEMCLOCK_H
