//
// Created by Fedorov, Alex on 1/28/18.
//

#ifndef MARKOS_STDOUTLOGGERFACTORY_H
#define MARKOS_STDOUTLOGGERFACTORY_H


#include <logger/LoggerFactory.h>

class StdOutLoggerFactory : public LoggerFactory {
public:
    Logger *createLogger(const char *name) override;
};


#endif //MARKOS_STDOUTLOGGERFACTORY_H
