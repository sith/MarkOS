//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MARKIMODELISTENER_H
#define MARK1_MARKIMODELISTENER_H


#include "ModeListener.h"
#include "../logger/Logger.h"

class ModeManager : public ModeListener {
    Mode *currentMode;
    Logger *logger;

    void deleteCurrentMode();

public:
    ModeManager();

    virtual ~ModeManager();

    Mode &getCurrentMode() const;

    void onModeChange(ModeName mode) override;
};


#endif //MARK1_MARKIMODELISTENER_H