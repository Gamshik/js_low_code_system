#ifndef NESTJSCONTROLLERFILE_H
#define NESTJSCONTROLLERFILE_H


#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

class NestJsControllerFile : public NestJsProjectFile
{
private:
    const char* NAME_VARIABLE_PATTERN = "{controllerName}";
    const char* SERVICE_NAME_VARIABLE_PATTERN = "{serviceName}";
    const char* SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{serviceNameCamelCase}";

    char* _name;
    char* _serviceName;
    char* _serviceNameCamelCase;

public:
    NestJsControllerFile(const char* name, const char* serviceName):
        NestJsProjectFile("controller.ts.txt")
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();

        _serviceName = StringHelper::Duplicate_String(serviceName);
        if (!_serviceName) throw std::bad_alloc();

        _serviceNameCamelCase = StringHelper::Duplicate_String(StringHelper::To_lower_case_first_letter(serviceName));
        if (!_serviceNameCamelCase) throw std::bad_alloc();
    }
    virtual ~NestJsControllerFile() 
    {
        free(_name);
        free(_serviceName);
        free(_serviceNameCamelCase);
    }

    void createFile(const char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(NAME_VARIABLE_PATTERN, _name, file_content);

        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(SERVICE_NAME_VARIABLE_PATTERN, _serviceName, file_content);

        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _serviceNameCamelCase, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSCONTROLLERFILE_H
