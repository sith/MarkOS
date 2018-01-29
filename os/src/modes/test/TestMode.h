#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include <logger/Logger.h>
#include "../Mode.h"
#include "../../time/TimerListener.h"
class TestMode : public Mode, TimerListener {
private:
    int delayInMilliSeconds = 1000;

    bool startNewTimer = true;
    Logger *logger;

public:
    TestMode();

private:
    void onEvent() override;

public:
    virtual ~TestMode();

    const void process() override;

};


#endif //MARK1_TESTMODE_H
