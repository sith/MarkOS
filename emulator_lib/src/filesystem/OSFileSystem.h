//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARKOS_OSFILESYSTEM_H
#define MARKOS_OSFILESYSTEM_H


#include <filesystem/FileSystem.h>

using namespace mark_os::filesystem;
class OSFileSystem : public FileSystem {
    Pointer<File> openFile(const char *path) override;

    void deleteFile(const char *path) override;

    void createDirectory(const char *path) override;
};


#endif //MARKOS_OSFILESYSTEM_H
