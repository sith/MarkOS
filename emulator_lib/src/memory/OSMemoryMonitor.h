//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_OSMEMORYMONITOR_H
#define MARKOS_OSMEMORYMONITOR_H


#include <memory/MemoryMonitor.h>

class OSMemoryMonitor : public MemoryMonitor {
public:
    int available() override;
};


#endif //MARKOS_OSMEMORYMONITOR_H
