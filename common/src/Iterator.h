//
// Created by Oleksandra Baukh on 1/20/18.
//

#ifndef MARKOS_ITERATOR_H
#define MARKOS_ITERATOR_H

template<class T>
class Iterator {
public:
    virtual bool hasNext()= 0;

    virtual T *next()= 0;
};

#endif //MARKOS_ITERATOR_H
