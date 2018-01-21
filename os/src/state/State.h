//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_STATE_H
#define MARKOS_STATE_H

template<class T>
class TransitionFunction;

enum StateStatus {
    WAITING,
    IN_PROGRESS,
    DONE,

};

class State {
protected:
    StateStatus stateStatus = WAITING;
public:

    virtual State &execute()= 0;

    virtual void cancel()=0;

    virtual void reset()=0;
};

class EmptyStateValue {

};

template<class T>
class TransitionFunction {
public:
    virtual State &nextState(T &stateValue)= 0;
};


#endif //MARKOS_STATE_H
