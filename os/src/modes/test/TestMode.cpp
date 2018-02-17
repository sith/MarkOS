#include <environment/Environment.h>
#include <state/DirectTransition.h>
#include "TestMode.h"
#include "state/standard/PrintState.h"

const void TestMode::process() {
    currentState = currentState->execute();
}

TestMode::TestMode() : Mode(ModeName::TEST),
                       logger{LoggerFactory::newLogger("TestMode")},
                       directTransitionPrintState(printState),
                       directTransitionToWaitState(waitState) {
    waitState.setTransitionFunction(directTransitionPrintState);
    printState.setTransitionFunction(directTransitionToWaitState);

    currentState = &printState;
}


void TestMode::stop() {
    waitState.stop();
    printState.stop();
    currentState = &printState;
}

void TestMode::init() {

}
