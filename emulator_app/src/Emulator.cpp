//
// Created by Fedorov, Alex on 1/29/18.
//


#include <logger/StdOutLogger.h>
#include <environment/Environment.h>
#include <clock/SystemClock.h>
#include <iostream>

void setup() {

    SystemClock *systemClock = new SystemClock;
    Timer *timer = new Timer(*systemClock);
    Environment::getEnvironment().setTimer(timer);


}


void loop() {

}


int main(int argc, char **argv) {

    setup();


    while (true) {
        loop();
    }

    return 0;
}
