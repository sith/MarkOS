//
// Created by Fedorov, Alex on 2/3/18.
//

#ifndef MARKOS_MOCKCONTROLLER_H
#define MARKOS_MOCKCONTROLLER_H

#include <controller/Controller.h>
#include "gmock/gmock.h"

class MockController : public Controller {
public:

    MockController(Logger *logger) : Controller(logger) {}

    MOCK_METHOD1(onEvent,
    void(unsigned long cycleNumber));
    MOCK_METHOD0(readControllerCommand,
            Command());
};


#endif //MARKOS_MOCKCONTROLLER_H
