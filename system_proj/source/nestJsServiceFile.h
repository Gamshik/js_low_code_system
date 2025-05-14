#ifndef NESTJSSERVICEFILE_H
#define NESTJSSERVICEFILE_H


#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

class NestJsServiceFile : public NestJsProjectFile
{
private:
    const char* NAME_VARIABLE_PATTERN = "{serviceName}";

    char* _name;

public:
    NestJsServiceFile(const char* name):
        NestJsProjectFile("service.ts.txt")
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();
    }
    virtual ~NestJsServiceFile() 
    {
        free(_name);
    }

    void createFile(char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(NAME_VARIABLE_PATTERN, _name, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSSERVICEFILE_H
