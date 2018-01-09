//
// Created by Oleksandra Baukh on 1/8/18.
//

#ifndef MARKOS_QUEUE_H
#define MARKOS_QUEUE_H

template<class T>
class Queue {

    virtual void add(T *t)=0;

    virtual T *poll()=0;

    virtual T *peek()=0;

    virtual int size()=0;

};

#endif //MARKOS_QUEUE_H
