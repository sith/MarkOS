//
// Created by Fedorov, Alex on 1/29/18.
//


#include <logger/StdOutLogger.h>
#include <environment/Environment.h>
#include <clock/SystemClock.h>
#include <iostream>

void someMethod();

void setup() {

    SystemClock *systemClock = new SystemClock;
    Timer *timer = new Timer(*systemClock);
    Environment::getEnvironment().setTimer(timer);


}


void loop() {

}


int main(int argc, char **argv) {

/*
    while (true) {
        loop();
    }*/

/*

    SystemClock clock;

    std::cout << clock.getTime();
*/

    std::string name;
    if (std::cin.peek()) {
        getline(std::cin, name);

        if (!name.empty()) {
            std::cout << name;
        }
    }


    return 0;
}
