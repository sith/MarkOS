//
// Created by Oleksandra Baukh on 1/22/18.
//

#include "SimpleTest.h"

TEST_F(SimpleTest, simpleTest) {
    MyMock myMock;
    EXPECT_CALL(myMock, doSomething()).Times(1);
}
