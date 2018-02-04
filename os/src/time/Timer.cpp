//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "Timer.h"
#include "../environment/Environment.h"

void Timer::addTimer(int milliseconds, TimerListener &timerListener) {
    logger->newLine()->logAppend("New timer task is accepted. Delay: ")->logAppend(milliseconds);
    tasks->add(new TimerTask(Environment::getEnvironment().getClock()->getTime() + milliseconds, &timerListener));
}

void Timer::onEvent(unsigned long cycleNumber) {
    auto *iterator = tasks->iterator();
    long currentTime = Environment::getEnvironment().getClock()->getTime();
    while (iterator->hasNext()) {
        auto timerTask = iterator->next();
        if (timerTask->isDone(currentTime)) {
            logger->newLine()->logAppend("Task is done.");
            timerTask->getListener()->onEvent();
            TimerTask *doneTask = iterator->remove();
            delete doneTask;
        }
    }
    delete iterator;
}

Timer::Timer() : logger(LoggerFactory::newLogger("Timer")) {}

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
