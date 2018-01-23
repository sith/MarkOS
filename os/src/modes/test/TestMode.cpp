#include "TestMode.h"
#include "PrintState.h"
#include "WaitState.h"
#include "../ModeName.h"
#include "../../state/NoopState.h"
#include "../../state/DirectTransition.h"

const void TestMode::process() {
    next();
}

const void TestMode::stop() {
    return stopStateMachine();
}

TestMode::TestMode() : Mode(ModeName::TEST), StateMachine(), state(new NoopState) {
}

State *TestMode::init() {
    auto *printState = new PrintState();
    stopableStates->add(printState);

    auto *waitState = new WaitState(1000);
    stopableStates->add(waitState);

    printState->setTransitionFunction(new DirectTransition(*waitState));
    waitState->setTransitionFunction(new DirectTransition(*printState));
    return printState;
}
