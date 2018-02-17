//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "Cycle.h"


unsigned long Cycle::getCycle() const {
    return cycleNumber;
}

void Cycle::next() {
    cycleNumber++;
    auto iteratorPointer = listeners->iterator();
    Iterator<CycleListener> &iterator = *iteratorPointer.get();
    while (iterator.hasNext()) {
        CycleListener *pListener = iterator.next();
        pListener->onEvent(cycleNumber);
    }
}

List<CycleListener> *Cycle::getListeners() const {
    return listeners;
}

