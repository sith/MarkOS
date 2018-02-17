//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_CYCLE_H
#define MARK1_CYCLE_H


#include <collections/LinkedList.h>
#include "CycleListener.h"

class Cycle {
    unsigned long cycleNumber = 0;
    List<CycleListener> *listeners = new LinkedList<CycleListener>();
public:
    unsigned long getCycle() const;

    void next();

    List<CycleListener> *getListeners() const;

};


#endif //MARK1_CYCLE_H
