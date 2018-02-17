//
// Created by Fedorov, Alex on 2/2/18.
//

#include <environment/Environment.h>
#include "WaitState.h"

State *WaitState::execute() {
    switch (stateStatus) {
        case WAITING:
            Environment::getEnvironment().getTimer().addTimer(waitTime, *this);
            stateStatus = IN_PROGRESS;
            return this;
        case IN_PROGRESS:
            return this;
        case DONE:
            stateStatus = WAITING;
            EmptyStateValue e;
            return transitionFunction->nextState(e);
    }
    return this;
}


void WaitState::onEvent() {
    stateStatus = DONE;
}

WaitState::WaitState(int waitTime) : waitTime(waitTime),
                                     logger{LoggerFactory::newLogger("WaitState")} {}

void WaitState::setTransitionFunction(TransitionFunction<EmptyStateValue> &transitionFunction) {
    WaitState::transitionFunction = &transitionFunction;
}

void WaitState::stop() {
    State::stop();
    Environment::getEnvironment().getTimer().removeTasksForListener(*this);
}

WaitState::~WaitState() {}
