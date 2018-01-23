//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_STATEMACHINE_H
#define MARKOS_STATEMACHINE_H


#include <List.h>
#include <LinkedList.h>
#include "State.h"
#include "NoopState.h"

class StateMachine {
    State *currentState = new NoopState;
protected:
    List<State> *stopableStates = new LinkedList<State>;
public:
    State *getCurrentState() const;

    StateMachine();

    virtual State *init()=0;

    virtual void next();

    void stopStateMachine();
};


#endif //MARKOS_STATEMACHINE_H
