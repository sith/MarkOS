//
// Created by Oleksandra Baukh on 1/8/18.
//

#ifndef MARKOS_LINKEDLIST_H
#define MARKOS_LINKEDLIST_H


#include "List.h"
#include "Queue.h"

namespace common {
    template<class T>
    class LinkedList : public List<T>, Queue<T> {
    public:
        void add(T *t) override;

        T *get(int index) override;

        T *remove(int index) override;

        int size() override;

    private:
        T *poll() override;

        T *peek() override;
    };
}

#endif //MARKOS_LINKEDLIST_H
