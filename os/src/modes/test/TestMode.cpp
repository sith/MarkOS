#include <environment/Environment.h>
#include "TestMode.h"
#include "PrintState.h"
#include "WaitState.h"
#include "../ModeName.h"
#include "../../state/NoopState.h"
#include "../../state/DirectTransition.h"

const void TestMode::process() {
}

TestMode::TestMode() : Mode(ModeName::TEST),
                       logger(Environment::getEnvironment().getLoggerFactory()->createLogger("TestMode")) {
    logger->newLine()->logAppend("Started");
}

TestMode::~TestMode() {
    delete logger;
}
/*

State *TestMode::init() {
   auto *printState = new PrintState();
     stopableStates->add(printState);

     auto *waitState = new WaitState(1000);
     stopableStates->add(waitState);

     printState->setTransitionFunction(new DirectTransition(*waitState));
     waitState->setTransitionFunction(new DirectTransition(*printState));
     return printState;*//*

    return new NoopState;
}
*/
