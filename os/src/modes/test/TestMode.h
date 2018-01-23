//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include "../Mode.h"
#include "../../state/State.h"
#include "../../state/StateMachine.h"

class TestMode : public Mode, StateMachine {
private:
    State *state;

public:
    TestMode();

private:
    State *init() override;

public:
    const void process() override;

    const void stop() override;

};


#endif //MARK1_TESTMODE_H
