//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_FILE_H
#define MARKOS_FILE_H


#include <memory/Pointer.h>

class File {
public:
    virtual ~File() {
    }

    virtual int readInt()= 0;

    virtual Pointer<const char *> readString()= 0;
};


#endif //MARKOS_FILE_H
