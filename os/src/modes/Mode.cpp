//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "ModeName.h"
#include "Mode.h"


Mode::Mode(ModeName modeName) : modeName(modeName) {}

ModeName &Mode::getModeName() {
    return modeName;
}

const char *Mode::getModeNameString() {
    return getModeNameString(modeName);
}

const char *Mode::getModeNameString(ModeName &modeName) {
    switch (modeName) {
        case ModeName::NONE:
            return "NONE";
        case ModeName::CALIBRATION:
            return "CALIBRATION";
        case ModeName::FREE_RUN:
            return "FREE_RUN";
        case ModeName::SUPERVISED:
            return "SUPERVISED";
        case ModeName::FIXED_ROUTE:
            return "FIXED_ROUTE";
        case ModeName::EXPLORER:
            return "EXPLORER";
        case ModeName::TEST:
            return "TEST";
        default:
            return "NotDefined";
    }
}

Mode::~Mode() {

}
