#include "ModeManager.h"
#include "ModeName.h"
#include "../environment/Environment.h"
#include "test/TestMode.h"

void ModeManager::onModeChange(ModeName mode) {

    if (currentMode->getModeName() == mode) {
        return;
    }
    stopCurrentMode();
    switch (mode) {
        case ModeName::CALIBRATION:
            break;
        case ModeName::FREE_RUN:
            break;
        case ModeName::SUPERVISED:
            initMode(supervisedMode);
            break;
        case ModeName::FIXED_ROUTE:
            break;
        case ModeName::EXPLORER:
            break;
        case ModeName::TEST:
            initMode(testMode);
            break;
        case ModeName::NONE:
            currentMode = &noopMode;
            break;
        default:
            return;
    }
}

void ModeManager::stopCurrentMode() {
    logger->newLine()->logAppend("Delete mode: ")->logAppend(currentMode->getModeNameString());
    currentMode->stop();
    currentMode = &noopMode;
}

ModeManager::ModeManager() : logger(LoggerFactory::newLogger("ModeManager")) {
    currentMode = &noopMode;
}

Mode &ModeManager::getCurrentMode() const {
    return *currentMode;
}

ModeManager::~ModeManager() {
    delete currentMode;
    delete logger;
}

void ModeManager::initMode(Mode &newMode) {
    currentMode = &newMode;
    currentMode->init();
}
