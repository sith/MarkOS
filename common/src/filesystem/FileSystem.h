//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_FILESYSTEM_H
#define MARKOS_FILESYSTEM_H


#include <memory/Pointer.h>
#include "File.h"

class FileSystem {
public:
    virtual Pointer<File> openFile(char const *path)= 0;

    virtual void createDirectory(char const *path)= 0;

};


#endif //MARKOS_FILESYSTEM_H
