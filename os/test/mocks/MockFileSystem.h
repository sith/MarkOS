//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MOCKFILESYSTEM_H
#define MARKOS_MOCKFILESYSTEM_H

#include <filesystem/FileSystem.h>
#include "gmock/gmock.h"

class MockFileSystem : public FileSystem {
public:
    MOCK_METHOD1(openFile,
            Pointer<File>(char const *path));
    MOCK_METHOD1(createDirectory,
    void(char const *path));
};

#endif //MARKOS_MOCKFILESYSTEM_H
