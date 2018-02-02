//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_MODE_H
#define MARK1_MODE_H

#include "ModeName.h"

class Mode {
    ModeName modeName;
public:
    Mode(ModeName modeName);

    virtual ~Mode() = 0;

    virtual const void process()=0;

    ModeName &getModeName();

    const char *getModeNameString();

    virtual void stop()= 0;

    static const char *getModeNameString(ModeName &modeName);
};

class NoopMode : public Mode {
public:
    const void process() override {
    }

    NoopMode() : Mode(ModeName::NONE) {};

    void stop() override {

    }
};

#endif //MARK1_MODE_H

