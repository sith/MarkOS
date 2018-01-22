//
// Created by Oleksandra Baukh on 1/21/18.
//

#ifndef MARKOS_MOCKCYCLELISTENER_H
#define MARKOS_MOCKCYCLELISTENER_H

#include "../../src/cycle/CycleListener.h"
#include "gmock/gmock.h"

class MockCycleListener : public CycleListener {
public:
    MOCK_METHOD1(onEvent, void(unsigned long
            cycleNumber));
};

#endif //MARKOS_MOCKCYCLELISTENER_H
