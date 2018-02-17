//
// Created by Oleksandra Baukh on 2/17/18.
//

#ifndef MARKOS_POINTER_H
#define MARKOS_POINTER_H

/**
 * Pointer takes the reference to the object allocated in free memory and removes it when Pointer is deleted
 * @tparam T
 */
template<typename T>
class Pointer {
    T *pointer;
public:
    Pointer(T *pointer) : pointer(pointer) {}

    virtual ~Pointer() {
        delete pointer;
        pointer = nullptr;
    }

    T *get() const {
        return pointer;
    }
};


#endif //MARKOS_POINTER_H
