//
// Created by Oleksandra Baukh on 1/20/18.
//

#include "WaitState.h"
#include "../../environment/Environment.h"
#include "../../state/NoopState.h"

State &WaitState::execute() {
    switch (stateStatus) {
        case WAITING:
            Environment::getEnvironment().getTimer()->addTimer(waitTime, *this);
            stateStatus = StateStatus::IN_PROGRESS;
            return *this;
        case IN_PROGRESS:
            return *this;
        case DONE:
            stateStatus = WAITING;
            return transitionFunction->nextState(*new EmptyStateValue);
        default:
            return *new NoopState;
    }
}

void WaitState::stop() {
//    Environment::getEnvironment().getTimer()->addTimer(waitTime, *this);

}

void WaitState::onEvent() {
    stateStatus = StateStatus::DONE;
}


WaitState::WaitState(int waitTime) : waitTime(waitTime) {}

void WaitState::setTransitionFunction(TransitionFunction<EmptyStateValue> *transitionFunction) {
    WaitState::transitionFunction = transitionFunction;
}
