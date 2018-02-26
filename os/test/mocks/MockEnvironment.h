//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_MOCKENVIRONMENT_H
#define MARKOS_MOCKENVIRONMENT_H

#include "gmock/gmock.h"
#include "../../src/environment/Environment.h"

class MockEnvironment : public Environment {
public:
    MOCK_METHOD0(getModeManager,
                 ModeManager & ());

    MOCK_METHOD0(getCycle,
                 Cycle & ());

    MOCK_METHOD0(getTimer,
                 Timer & ());

    MOCK_METHOD0(getController,
                 Controller & ());

    MOCK_METHOD0(getClock,
                 Clock & ());

    MOCK_METHOD0(getMotorDriver,
                 MotorDriver & ());

    MOCK_METHOD0(getObstacleSensor,
                 ObstacleSensor & ());

    MOCK_METHOD0(getFileSystem,
                 FileSystem & ());

    MOCK_METHOD0(getMemoryMonitor,
                 MemoryMonitor & ());
};


#endif //MARKOS_MOCKENVIRONMENT_H
