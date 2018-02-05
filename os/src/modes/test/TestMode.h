#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include <logger/Logger.h>
#include <state/State.h>
#include <state/standard/PrintState.h>
#include <state/standard/WaitState.h>
#include <state/DirectTransition.h>
#include "../Mode.h"
#include "../../time/TimerListener.h"

class TestMode : public Mode {
    State *currentState;
    Logger *logger;
    PrintState printState;
    WaitState waitState{1000};
    DirectTransition directTransitionPrintState;
    DirectTransition directTransitionToWaitState;

public:
    TestMode();

public:
    virtual ~TestMode();

    const void process() override;

    void stop() override;

    void init() override;

};


#endif //MARK1_TESTMODE_H
