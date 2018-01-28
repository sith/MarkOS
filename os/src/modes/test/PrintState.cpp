//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "PrintState.h"
#include "../../environment/Environment.h"

State &PrintState::execute() {
    logger->newLine()->logAppend("Print message: ")->logAppend(Environment::getEnvironment().getClock()->getTime());
    return transitionFunction->nextState(*new EmptyStateValue);
}

void PrintState::setTransitionFunction(TransitionFunction<EmptyStateValue> *transitionFunction) {
    PrintState::transitionFunction = transitionFunction;
}

void PrintState::stop() {

}



PrintState::PrintState() : logger(
        Environment::getEnvironment().getLoggerFactory()->createLogger("PrintState")) {}
