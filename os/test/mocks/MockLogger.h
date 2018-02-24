//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_MOCKLOGGER_H
#define MARKOS_MOCKLOGGER_H

#include <logger/Logger.h>
#include "gmock/gmock.h"

class MockLogger : public Logger {
public:
    MOCK_METHOD1(logAppend,
                 Logger*(
                         const char *c));

    MOCK_METHOD1(logAppend,
                 Logger*(
                         int number));

    MOCK_METHOD1(logAppend,
                 Logger*(
                         long number));

    MOCK_METHOD0(newLine,
                 Logger*());
};

#endif //MARKOS_MOCKLOGGER_H
