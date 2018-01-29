//
// Created by Fedorov, Alex on 1/29/18.
//


#include <logger/StdOutLogger.h>

void someMethod();

void setup() {

}


void loop() {

}


int main(int argc, char **argv) {
    someMethod();
    return 0;
}

void someMethod() {
    StdOutLogger logger("TestLogger");
    logger.newLine()->logAppend("Hello world");
}
