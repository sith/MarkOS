//
// Created by Fedorov, Alex on 1/28/18.
//

#include "StdOutLoggerFactory.h"
#include "StdOutLogger.h"

Logger *StdOutLoggerFactory::createLogger(const char *name) {
    return new StdOutLogger(name);
}
