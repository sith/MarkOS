//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "Cycle.h"


unsigned long Cycle::getCycle() const {
    return cycleNumber;
}

void Cycle::next() {
    cycleNumber++;
    Iterator<CycleListener> *iterator = &listeners->iterator();
    while (iterator->hasNext()) {
        CycleListener *pListener = iterator->next();
        pListener->onEven(cycleNumber);
    }
}

List<CycleListener> *Cycle::getListeners() const {
    return listeners;
}

