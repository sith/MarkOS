//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MARKIMODELISTENER_H
#define MARK1_MARKIMODELISTENER_H


#include <modes/test/TestMode.h>
#include <modes/supervised/SupervisedMode.h>
#include "ModeListener.h"
#include "../logger/Logger.h"

class ModeManager : public ModeListener {
    Mode *currentMode;

    TestMode testMode;
    NoopMode noopMode;
    SupervisedMode supervisedMode;

    Logger *logger;

    void deleteCurrentMode();

public:
    ModeManager();

    virtual ~ModeManager();

    Mode &getCurrentMode() const;

    void onModeChange(ModeName mode) override;

    void initMode(Mode &pMode);
};


#endif //MARK1_MARKIMODELISTENER_H
