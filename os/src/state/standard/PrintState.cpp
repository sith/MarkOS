//
// Created by Fedorov, Alex on 2/2/18.
//

#include <environment/Environment.h>
#include "PrintState.h"

State *PrintState::execute() {
    logger.get()->newLine()->logAppend("Hello world");
    EmptyStateValue e;
    return transitionFunction->nextState(e);
}

PrintState::PrintState() : logger(LoggerFactory::newLogger("PrintState")) {}


void PrintState::setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction) {
    PrintState::transitionFunction = &transitionFunction;
}

PrintState::~PrintState() {}
