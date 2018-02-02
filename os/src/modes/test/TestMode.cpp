#include <environment/Environment.h>
#include "TestMode.h"
#include "PrintState.h"
#include "WaitState.h"
#include "../ModeName.h"
#include "../../state/NoopState.h"
#include "../../state/DirectTransition.h"

const void TestMode::process() {
    if (startNewTimer) {
        logger->newLine()->logAppend("Start new timer with delay: ")->logAppend(delayInMilliSeconds)->logAppend("ms");
        Environment::getEnvironment().getTimer()->addTimer(delayInMilliSeconds, *this);
        startNewTimer = false;
        delayInMilliSeconds *= 2;
    }
}

TestMode::TestMode() : Mode(ModeName::TEST),
                       logger(Environment::getEnvironment().getLoggerFactory()->createLogger("TestMode")) {
    logger->newLine()->logAppend("Started");
}

TestMode::~TestMode() {
    Environment::getEnvironment().getTimer()->removeTasksForListener(*this);
    delete logger;
}

void TestMode::onEvent() {
    startNewTimer = true;
}
