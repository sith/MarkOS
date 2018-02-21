//
// Created by Fedorov, Alex on 2/2/18.
//

#include <environment/Environment.h>
#include "PrintState.h"

State *PrintState::execute() {
    logger.get()->newLine()->logAppend("Hello world");
    return transitionFunction->nextState(EmptyStateValue::EMPTY_STATE_VALUE);
}

PrintState::PrintState() : logger(LoggerFactory::newLogger("PrintState")) {}


void PrintState::setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction) {
    PrintState::transitionFunction = &transitionFunction;
}

PrintState::~PrintState() {}
