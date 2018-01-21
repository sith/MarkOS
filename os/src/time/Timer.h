//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_TIMER_H
#define MARK1_TIMER_H


#include <LinkedList.h>
#include "TimerListener.h"
#include "TimerTask.h"
#include "../CycleListener.h"
#include "Clock.h"

class Timer : public CycleListener {
    List<TimerTask> *tasks = new LinkedList<TimerTask>();
    Clock *clock;
public:
    Timer();

    void onEven(unsigned long cycleNumber) override;

    void addTimer(int milliseconds, TimerListener &timerListener);
};


#endif //MARK1_TIMER_H
