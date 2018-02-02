//
// Created by Fedorov, Alex on 1/29/18.
//

#ifndef MARKOS_SYSTEMCLOCK_H
#define MARKOS_SYSTEMCLOCK_H


#include <time/Clock.h>
#include <ctime>
#include <sys/time.h>

class SystemClock : public Clock {
    timeval startTime;
    long toMilliseconds(const timeval &time) const;
public:

    SystemClock();

    long getTime() override;

    virtual ~SystemClock();
};


#endif //MARKOS_SYSTEMCLOCK_H
