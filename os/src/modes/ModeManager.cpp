//
// Created by Oleksandra Baukh on 1/17/18.
//

#include "ModeManager.h"
#include "ModeName.h"
#include "../environment/Environment.h"
#include "test/TestMode.h"

void ModeManager::onModeChange(ModeName mode) {

    if (currentMode->getModeName() == mode) {
        return;
    }
    switch (mode) {
        case ModeName::TEST:
            currentMode->stop();
            currentMode = new TestMode;
            break;
        case ModeName::NONE:
            currentMode->stop();
            currentMode = new NoopMode;
            break;
        default:
            return;
    }
}

ModeManager::ModeManager() : logger(&Environment::getEnvironment().getLoggerFactory()->createLogger("ModeManager")) {}

Mode *ModeManager::getCurrentMode() const {
    return currentMode;
}
