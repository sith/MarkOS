//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARK1_NOOPSTATE_H
#define MARK1_NOOPSTATE_H


#include "State.h"

class NoopState : public State{
public:
    State &execute() override;

    void cancel() override;

    void reset() override;
};


#endif //MARK1_NOOPSTATE_H
