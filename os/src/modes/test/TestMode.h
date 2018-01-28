//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include <logger/Logger.h>
#include "../Mode.h"
#include "../../state/State.h"
#include "../../state/StateMachine.h"

class TestMode : public Mode {
private:
    State *state;
    Logger *logger;
public:
    TestMode();

    virtual ~TestMode();

    const void process() override;

};


#endif //MARK1_TESTMODE_H
