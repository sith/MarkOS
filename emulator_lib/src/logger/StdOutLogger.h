//
// Created by Fedorov, Alex on 1/28/18.
//

#ifndef MARKOS_STDOUTLOGGER_H
#define MARKOS_STDOUTLOGGER_H


#include <logger/Logger.h>
#include <cycle/CycleListener.h>

class StdOutLogger : public Logger, CycleListener {
    const char *name;
    unsigned long cycle = 0;
public:
    StdOutLogger(const char *name);

private:
    void onEvent(unsigned long cycleNumber) override;

public:
    virtual ~StdOutLogger();

    Logger *logAppend(const char *c) override;

    Logger *logAppend(int number) override;

    Logger *logAppend(long number) override;

    Logger *newLine() override;
};


#endif //MARKOS_STDOUTLOGGER_H
