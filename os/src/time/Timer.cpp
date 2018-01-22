//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "Timer.h"
#include "../environment/Environment.h"

void Timer::addTimer(int milliseconds, TimerListener &timerListener) {
    tasks->add(new TimerTask(clock->getTime() + milliseconds, &timerListener));
}

void Timer::onEvent(unsigned long cycleNumber) {
    auto *iterator = &tasks->iterator();

    while (iterator->hasNext()) {
        auto timerTask = iterator->next();

        if (timerTask->isDone(clock->getTime())) {
            timerTask->getListener()->onEvent();
            iterator->remove();
        }
    }
}

Timer::Timer() : clock(Environment::getEnvironment().getClock()) {}
