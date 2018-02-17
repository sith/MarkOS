#include "Timer.h"
#include "../environment/Environment.h"

void Timer::addTimer(int milliseconds, TimerListener &timerListener) {
    logger->newLine()->logAppend("New timer task is accepted. Delay: ")->logAppend(milliseconds);
    tasks.get()->add(new TimerTask(clock->getTime() + milliseconds, &timerListener));
}

void Timer::onEvent(unsigned long cycleNumber) {
    auto iteratorPointer = tasks.get()->iterator();
    auto *iterator = iteratorPointer.get();
    long currentTime = clock->getTime();
    while (iterator->hasNext()) {
        auto timerTask = iterator->next();
        if (timerTask->isDone(currentTime)) {
            logger->newLine()->logAppend("Task is done.");
            timerTask->getListener()->onEvent();
            TimerTask *doneTask = iterator->remove();
            delete doneTask;
        }
    }
}

Timer::Timer() : Timer(Environment::getEnvironment().getClock()) {}

Timer::Timer(Clock *clock) : clock(clock), logger(LoggerFactory::newLogger("Timer")) {}

void Timer::removeTasksForListener(TimerListener &timerListener) {
    auto iteratorPointer = tasks.get()->iterator();
    Iterator<TimerTask> *iterator = iteratorPointer.get();
    while (iterator->hasNext()) {
        TimerTask *timerTask = iterator->next();
        if (timerTask->getListener() == &timerListener) {
            delete iterator->remove();
        }
    }
}

Timer::~Timer() {
}
