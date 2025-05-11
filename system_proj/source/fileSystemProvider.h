#ifndef FILESYSTEMPROVIDER_H
#define FILESYSTEMPROVIDER_H

#include <Windows.h>

class FileSystemProvider
{
private:
    inline static const char* INSTANCE_FILES_DIR = "file_instances";
    static BOOL Create_Directory_If_Not_Exist(char* path);
    static BOOL Create_Directories_If_Not_Exist_Recursively(char* path);

public:
    FileSystemProvider() = delete;

    static char* Read_Instance_File(char* name);
    static BOOL Create_File(char* path, char* content);
};

#endif // FILESYSTEMPROVIDER_H
