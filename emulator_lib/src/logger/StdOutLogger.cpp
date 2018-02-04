//
// Created by Fedorov, Alex on 1/28/18.
//

#include <iostream>
#include <environment/Environment.h>
#include "StdOutLogger.h"

Logger *StdOutLogger::logAppend(const char *c) {
    std::cout << c;
    std::cout.flush();
    return this;
}

Logger *StdOutLogger::logAppend(int number) {
    std::cout << number;
    std::cout.flush();
    return this;
}

Logger *StdOutLogger::logAppend(long number) {
    std::cout << number;
    std::cout.flush();
    return this;
}

Logger *StdOutLogger::newLine() {
    std::cout << "\n" << cycle << ":" << name << ": ";
    std::cout.flush();
    return this;
}

StdOutLogger::StdOutLogger(const char *name) : name(name) {

}

StdOutLogger::~StdOutLogger() {
}

void StdOutLogger::onEvent(unsigned long cycleNumber) {
    cycle = cycleNumber;
}
