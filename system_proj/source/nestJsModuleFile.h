#ifndef NESTJSMODULEFILE_H
#define NESTJSMODULEFILE_H

#include "nestJsProjectFile.h"
#include "stringHelper.h"

class NestJsModuleFile : public NestJsProjectFile
{
private:
    const char* NAME_VARIABLE_PATTERN = "{moduleName}";
    const char* SERVICE_NAME_VARIABLE_PATTERN = "{serviceName}";
    const char* CONTROLLER_NAME_VARIABLE_PATTERN = "{controllerName}";
    const char* SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{serviceNameCamelCase}";
    const char* CONTROLLER_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{controllerNameCamelCase}";

    char* _name;
    char* _serviceName;
    char* _controllerName;
    char* _serviceNameCamelCase;
    char* _controllerNameCamelCase;

public:
    NestJsModuleFile(const char* name):
        NestJsProjectFile("module.ts.txt")
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();

        _serviceName = StringHelper::Duplicate_String(name);
        if (!_serviceName) throw std::bad_alloc();

        _controllerName = StringHelper::Duplicate_String(name);
        if (!_controllerName) throw std::bad_alloc();

        _serviceNameCamelCase = StringHelper::To_lower_case_first_letter(name);
        if (!_serviceNameCamelCase) throw std::bad_alloc();

        _controllerNameCamelCase = StringHelper::To_lower_case_first_letter(name);
        if (!_controllerNameCamelCase) throw std::bad_alloc();
    }
    NestJsModuleFile(const char* name, const char* serviceName, const char* controllerName):
        NestJsProjectFile("module.ts.txt")
    {
        _name = StringHelper::Duplicate_String(name);
        if (!_name) throw std::bad_alloc();

        _serviceName = StringHelper::Duplicate_String(serviceName);
        if (!_serviceName) throw std::bad_alloc();

        _controllerName = StringHelper::Duplicate_String(controllerName);
        if (!_controllerName) throw std::bad_alloc();

        _serviceNameCamelCase = StringHelper::To_lower_case_first_letter(serviceName);
        if (!_serviceNameCamelCase) throw std::bad_alloc();

        _controllerNameCamelCase = StringHelper::To_lower_case_first_letter(controllerName);
        if (!_controllerNameCamelCase) throw std::bad_alloc();
    }
    virtual ~NestJsModuleFile() 
    {
        free(_name);
        free(_serviceName);
        free(_controllerName);
        free(_serviceNameCamelCase);
        free(_controllerNameCamelCase);
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

        temp_content = StringHelper::Set_variable_in_text(CONTROLLER_NAME_VARIABLE_PATTERN, _controllerName, file_content);
        
        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _serviceNameCamelCase, file_content);

        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(CONTROLLER_NAME_CAMEL_CASE_VARIABLE_PATTERN, _controllerNameCamelCase, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSMODULEFILE_H
