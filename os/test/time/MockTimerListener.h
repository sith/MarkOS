//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_MOCKTIMERLISTENER_H
#define MARKOS_MOCKTIMERLISTENER_H

#include <time/TimerListener.h>
#include "gmock/gmock.h"

class MockTimerListener : public TimerListener {
public:
    MOCK_METHOD0(onEvent,
                 void());
};

#endif //MARKOS_MOCKTIMERLISTENER_H
