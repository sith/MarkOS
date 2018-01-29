//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "Timer.h"
#include "../environment/Environment.h"

void Timer::addTimer(int milliseconds, TimerListener &timerListener) {
    tasks->add(new TimerTask(clock.getTime() + milliseconds, &timerListener));
}

void Timer::onEvent(unsigned long cycleNumber) {
    auto *iterator = tasks->iterator();
    long currentTime = clock.getTime();
    while (iterator->hasNext()) {
        auto timerTask = iterator->next();
        if (timerTask->isDone(currentTime)) {
            timerTask->getListener()->onEvent();
            delete iterator->remove();
        }
    }
    delete iterator;
}

Timer::Timer(Clock &clock) : clock(clock) {}

Timer::~Timer() {
    delete tasks;
}

void Timer::removeTasksForListener(TimerListener &timerListener) {

    Iterator<TimerTask> *iterator = tasks->iterator();

    while (iterator->hasNext()) {
        TimerTask *timerTask = iterator->next();
        if (timerTask->getListener() == &timerListener) {
            delete iterator->remove();
        }
    }

    delete iterator;
}
