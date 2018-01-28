//
// Created by Fedorov, Alex on 1/28/18.
//

#ifndef MARKOS_STDOUTLOGGER_H
#define MARKOS_STDOUTLOGGER_H


#include <logger/Logger.h>

class StdOutLogger : public Logger {
    const char *name;
public:
    StdOutLogger(const char *name);

    virtual ~StdOutLogger();

    Logger *logAppend(const char *c) override;

    Logger *logAppend(int number) override;

    Logger *logAppend(long number) override;

    Logger *newLine() override;
};


#endif //MARKOS_STDOUTLOGGER_H
