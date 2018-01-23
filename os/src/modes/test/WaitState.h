//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARK1_WAITSTATE_H
#define MARK1_WAITSTATE_H


#include "../../state/State.h"
#include "../../time/TimerListener.h"

class WaitState : public State, TimerListener {

    TransitionFunction<EmptyStateValue> *transitionFunction;
    int waitTime;

public:
    WaitState(int waitTime);

    void setTransitionFunction(TransitionFunction<EmptyStateValue> *transitionFunction);

    void onEvent() override;

    State &execute() override;

    void stop() override;
};


#endif //MARK1_WAITSTATE_H
