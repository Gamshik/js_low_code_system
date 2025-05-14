#ifndef NESTJSPACKAGEFILE_H
#define NESTJSPACKAGEFILE_H

#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

using namespace std;

class NestJsPackageFile : public NestJsProjectFile
{
private:
    const char* PROJ_NAME_VARIABLE_PATTERN = "{projName}";
    const char* ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    char* _projName;
    char* _rootDir;

public:
    NestJsPackageFile(const char* projName, const char* rootDir):
        NestJsProjectFile("package.json.txt")
    {
        _projName = StringHelper::Duplicate_String(projName);
        if (!_projName) throw std::bad_alloc();

        _rootDir = StringHelper::Duplicate_String(rootDir);
        if (!_rootDir) throw std::bad_alloc();
    }
    virtual ~NestJsPackageFile() 
    {
        free(_projName);
        free(_rootDir);
    }

    void createFile(const char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(PROJ_NAME_VARIABLE_PATTERN, _projName, file_content);
        
        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(ROOT_DIR_VARIABLE_PATTERN, _rootDir, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSPACKAGEFILE_H
