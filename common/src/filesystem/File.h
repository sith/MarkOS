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

private:
    int readInt();

    Pointer<const char *> readString();
};


#endif //MARKOS_FILE_H
