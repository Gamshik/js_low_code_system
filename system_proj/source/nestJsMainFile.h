#ifndef NESTJSMAINFILE_H
#define NESTJSMAINFILE_H

#include "nestJsProjectFile.h"
#include "stringHelper.h"

#include "iostream"

using namespace std;

class NestJsMainFile : public NestJsProjectFile
{
private:
    const char* MAIN_MODULE_NAME_VARIABLE_PATTERN = "{mainModuleName}";
    const char* MAIN_MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{mainModuleNameCamelCase}";

    char* _mainModuleName;
    char* _mainModuleNameCamelCase;

public:
    NestJsMainFile():
        NestJsProjectFile("main.ts.txt")
    {
        _mainModuleName = StringHelper::Duplicate_String("Main");
        if (!_mainModuleName) throw std::bad_alloc();

        _mainModuleNameCamelCase = StringHelper::Duplicate_String(StringHelper::To_lower_case_first_letter(_mainModuleName));
        if (!_mainModuleNameCamelCase) throw std::bad_alloc();
    }
    NestJsMainFile(char* moduleName):
        _mainModuleName(moduleName),
        _mainModuleNameCamelCase(StringHelper::To_lower_case_first_letter(moduleName)),
        NestJsProjectFile("main.ts.txt")
    {}
    virtual ~NestJsMainFile() 
    {
        free(_mainModuleName);
        free(_mainModuleNameCamelCase);
    }

    void createFile(const char* path)
    {
        char* file_content = FileSystemProvider::Read_File(instance_file_path);

        char* temp_content = StringHelper::Set_variable_in_text(MAIN_MODULE_NAME_VARIABLE_PATTERN, _mainModuleName, file_content);

        free(file_content);

        file_content = temp_content;

        temp_content = StringHelper::Set_variable_in_text(MAIN_MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _mainModuleNameCamelCase, file_content);

        free(file_content);

        file_content = temp_content;

        FileSystemProvider::Create_File(path, file_content);

        free(file_content);
    }
};

#endif // NESTJSMAINFILE_H
