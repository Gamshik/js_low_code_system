#ifndef NESTJSCLICONFIGFILE_H
#define NESTJSCLICONFIGFILE_H

#include <iostream>

#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

class NestJsCliConfigFile : public NestJsProjectFile
{
private:
    const char* ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    char* _rootDir;

public:
    NestJsCliConfigFile(char* rootDir):
        NestJsProjectFile("nest-cli.json.txt"),
        _rootDir(rootDir)
    {}
    virtual ~NestJsCliConfigFile() 
    {
        free(_rootDir);
    }

    void createFile(const char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(ROOT_DIR_VARIABLE_PATTERN, _rootDir, file_content);
        
        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSCLICONFIGFILE_H
