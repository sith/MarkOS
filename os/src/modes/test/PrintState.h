//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARK1_PRINTSTATE_H
#define MARK1_PRINTSTATE_H


#include "../../state/State.h"
#include "../../logger/Logger.h"

class PrintState : public State {
    Logger *logger;
    TransitionFunction<EmptyStateValue> *transitionFunction;
public:
    PrintState();
    State &execute() override;

    void stop() override;

    void setTransitionFunction(TransitionFunction<EmptyStateValue> *transitionFunction);
};


#endif //MARK1_PRINTSTATE_H
