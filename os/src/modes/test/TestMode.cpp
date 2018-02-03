#include <environment/Environment.h>
#include <state/DirectTransition.h>
#include "TestMode.h"
#include "state/standard/PrintState.h"

const void TestMode::process() {
    currentState = currentState->execute();
}

TestMode::TestMode() : Mode(ModeName::TEST),
                       logger(Environment::getEnvironment().getLoggerFactory()->createLogger("TestMode")),
                       directTransitionPrintState(printState),
                       directTransitionToWaitState(waitState) {
    waitState.setTransitionFunction(directTransitionPrintState);
    printState.setTransitionFunction(directTransitionToWaitState);

    currentState = &printState;
}

TestMode::~TestMode() {
    delete logger;
}

void TestMode::stop() {
    waitState.stop();
    printState.stop();
    currentState = &printState;
}
