//
// Created by Fedorov, Alex on 1/28/18.
//

#include "ModeManagerTest.h"

TEST_F(ModeManagerTest, basicTest) {
    modeManager->onModeChange(ModeName::NONE);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::NONE);

    modeManager->onModeChange(ModeName::TEST);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::TEST);

    modeManager->onModeChange(ModeName::NONE);
    ASSERT_EQ(modeManager->getCurrentMode().getModeName(), ModeName::NONE);
}

