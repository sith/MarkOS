//
// Created by Oleksandra Baukh on 1/22/18.
//

#include "StateMachine.h"

void StateMachine::next() {
    currentState = &currentState->execute();
}

StateMachine::StateMachine() {
    currentState = init();
}

State *StateMachine::getCurrentState() const {
    return currentState;
}

void StateMachine::stopStateMachine() {
    Iterator<State> *iterator = stopableStates->iterator();
    while (iterator->hasNext()) {
        iterator->next()->stop();
    }
    delete iterator;
}
