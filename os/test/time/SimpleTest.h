//
// Created by Oleksandra Baukh on 1/22/18.
//

#ifndef MARKOS_SIMPLETEST_H
#define MARKOS_SIMPLETEST_H

#include "gmock/gmock.h"

class SimpleTest : public ::testing::Test {

protected:
    class MyInterface {
        virtual void doSomething()=0;
    };

    class MyMock : public MyInterface {
    public:
        MOCK_METHOD0(doSomething,
                     void());
    };

};


#endif //MARKOS_SIMPLETEST_H
