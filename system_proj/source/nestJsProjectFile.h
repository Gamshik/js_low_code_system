#ifndef NESTJSPROJECTFILE_H
#define NESTJSPROJECTFILE_H

#include "fileSystemProvider.h"

using namespace std;

class NestJsProjectFile
{
protected:
    const char* INSTANCES_DIR_PATH = "file_instances\\";
    char* instance_file_path;

public:
    NestJsProjectFile(const char* instanceFilePath)
    {
        size_t pathLegth = strlen(INSTANCES_DIR_PATH) + strlen(instanceFilePath) + 1;
        instance_file_path = (char*)malloc(pathLegth);

        strcpy(instance_file_path, INSTANCES_DIR_PATH);
        strcat(instance_file_path, instanceFilePath);
    }
    virtual ~NestJsProjectFile() 
    {
        free(instance_file_path);
    }

    virtual void createFile(const char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSPROJECTFILE_H
