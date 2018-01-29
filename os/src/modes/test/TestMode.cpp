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
