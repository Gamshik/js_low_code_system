#ifndef FILESYSTEMPROVIDER_H
#define FILESYSTEMPROVIDER_H

#include <Windows.h>

class FileSystemProvider
{
private:
    static BOOL Create_Directory_If_Not_Exist(const char* path);
    static BOOL Create_Directories_If_Not_Exist_Recursively(const char* path);

public:
    FileSystemProvider() = delete;

    static char* Read_File(const char* name);
    static BOOL Create_File(const char* path, const char* content);
};

#endif // FILESYSTEMPROVIDER_H
