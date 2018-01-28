//
// Created by Fedorov, Alex on 1/28/18.
//

#include <iostream>
#include "StdOutLogger.h"

Logger *StdOutLogger::logAppend(const char *c) {
    std::cout << c;
    return this;
}

Logger *StdOutLogger::logAppend(int number) {
    std::cout << number;
    return this;
}

Logger *StdOutLogger::logAppend(long number) {
    std::cout << number;
    return this;
}

Logger *StdOutLogger::newLine() {
    std::cout << "\n" << name << ": ";
    return this;
}

StdOutLogger::StdOutLogger(const char *name) : name(name) {

}

StdOutLogger::~StdOutLogger() {
    delete name;
}
