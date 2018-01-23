//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_MODE_H
#define MARK1_MODE_H

#include "ModeName.h"

class Mode {
    ModeName &modeName;
public:
    Mode(ModeName modeName);

    virtual const void process()=0;

    virtual const void stop()=0;

    ModeName &getModeName() const;

    const char *getModeNameString();

    static const char *getModeNameString(ModeName &modeName);
};

class NoopMode : public Mode {
public:
    const void process() override {
    }

    NoopMode() : Mode(ModeName::NONE) {};

    const void stop() override {
    }
};

#endif //MARK1_MODE_H

