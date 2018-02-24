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
    Environment::getEnvironment().getController()->addListener(*supervisedMode);
    Environment::getEnvironment().setObstacleSensor(&obstacleSensor);

}

void SupervisedModeTest::TearDown() {
    Test::TearDown();
    delete supervisedMode;
}
TEST_F(SupervisedModeTest, basicTest) {
    EXPECT_CALL(mockMotorDriver, executeInternal(Direction::FORWARD, Speed::MEDIUM_SPEED)).Times(Exactly(1));
    supervisedMode->onEvent(Command::FORWARD);

    EXPECT_CALL(mockMotorDriver, executeInternal(Direction::BACKWARD, Speed::MEDIUM_SPEED)).Times(Exactly(1));
    supervisedMode->onEvent(Command::BACKWARD);

    EXPECT_CALL(mockMotorDriver, executeInternal(Direction::TURN_LEFT, Speed::LOW_SPEED)).Times(Exactly(1));
    supervisedMode->onEvent(Command::LEFT);

    EXPECT_CALL(mockMotorDriver, executeInternal(Direction::TURN_RIGHT, Speed::LOW_SPEED)).Times(Exactly(1));
    supervisedMode->onEvent(Command::RIGHT);

    EXPECT_CALL(mockMotorDriver, stopInternal()).Times(Exactly(1));
    supervisedMode->onEvent(Command::STOP);
}


TEST_F(SupervisedModeTest, doNothingForUnsupportedCommand) {
    EXPECT_CALL(mockMotorDriver, executeInternal(_, _)).Times(Exactly(0));
    supervisedMode->onEvent(Command::NONE);
}

TEST_F(SupervisedModeTest, stopMode) {
    EXPECT_CALL(mockMotorDriver, stopInternal()).Times(Exactly(1));
    supervisedMode->stop();

    ASSERT_EQ(Environment::getEnvironment().getController()->getCommandListeners()->size(), 0);
}


TEST_F(SupervisedModeTest, obstacle) {

    EXPECT_CALL(mockMotorDriver, stopInternal()).Times(Exactly(3));

    Obstacle forwardObstacle{false, true, false};
    supervisedMode->onEvent(forwardObstacle);

    Obstacle leftObstacle{true, false, false};
    supervisedMode->onEvent(leftObstacle);

    Obstacle rightObstacle{false, false, true};
    supervisedMode->onEvent(rightObstacle);
}

TEST_F(SupervisedModeTest, allowBackwardMovementWhenObstacleFound) {
    mockMotorDriver.execute(Direction::BACKWARD, Speed::LOW_SPEED);
    EXPECT_CALL(mockMotorDriver, stopInternal()).Times(Exactly(0));
    Obstacle obstacle = {true, false, false};
    supervisedMode->onEvent(obstacle);
}
