//
// Created by Oleksandra Baukh on 1/7/18.
//

#ifndef MARKOS_LIST_H
#define MARKOS_LIST_H

namespace common {
    template<class T>
    class List {
    public:
        virtual void add(T *t)=0;

        virtual T *get(int index)=0;

        virtual T *remove(int index)=0;

        virtual int size()=0;
    };
}
#endif //MARKOS_LIST_H
