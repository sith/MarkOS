//
// Created by Oleksandra Baukh on 2/4/18.
//

#include <environment/Environment.h>
#include "SupervisedModeTest.h"

using ::testing::Mock;
using ::testing::Exactly;
using ::testing::_;

void SupervisedModeTest::SetUp() {
    Test::SetUp();
    Mock::VerifyAndClearExpectations(&mockMotorDriver);
    Mock::VerifyAndClearExpectations(&mockController);

    supervisedMode = new SupervisedMode();

    Environment::getEnvironment().setMotorDriver(&mockMotorDriver);
    Environment::getEnvironment().setController(&mockController);
    Environment::getEnvironment().getController()->addControllerCommandListener(*supervisedMode);

}

void SupervisedModeTest::TearDown() {
    Test::TearDown();
    delete supervisedMode;
}

TEST_F(SupervisedModeTest, basicTest) {
    EXPECT_CALL(mockMotorDriver, execute(Direction::FORWARD, Speed::MEDIUM)).Times(Exactly(1));
    supervisedMode->onEvent(Command::FORWARD);

    EXPECT_CALL(mockMotorDriver, execute(Direction::BACKWARD, Speed::MEDIUM)).Times(Exactly(1));
    supervisedMode->onEvent(Command::BACKWARD);

    EXPECT_CALL(mockMotorDriver, execute(Direction::TURN_LEFT, Speed::LOW)).Times(Exactly(1));
    supervisedMode->onEvent(Command::LEFT);

    EXPECT_CALL(mockMotorDriver, execute(Direction::TURN_RIGHT, Speed::LOW)).Times(Exactly(1));
    supervisedMode->onEvent(Command::RIGHT);

    EXPECT_CALL(mockMotorDriver, stop()).Times(Exactly(1));
    supervisedMode->onEvent(Command::STOP);
}


TEST_F(SupervisedModeTest, doNothingForUnsupportedCommand) {
    EXPECT_CALL(mockMotorDriver, execute(_, _)).Times(Exactly(0));
    supervisedMode->onEvent(Command::NONE);
}

TEST_F(SupervisedModeTest, stopMode) {
    EXPECT_CALL(mockMotorDriver, stop()).Times(Exactly(1));
    supervisedMode->stop();

    ASSERT_EQ(Environment::getEnvironment().getController()->getCommandListeners()->size(), 0);


}
