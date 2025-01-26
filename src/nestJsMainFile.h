#ifndef NESTJSMAINFILE_H
#define NESTJSMAINFILE_H

#include "nestJsProjectFile.h"
#include "stringHelper.h"

#include "iostream"

using namespace std;

class NestJsMainFile : public NestJsProjectFile
{
private:
    const string MAIN_MODULE_NAME_VARIABLE_PATTERN = "{mainModuleName}";
    const string MAIN_MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{mainModuleNameCamelCase}";

    string _mainModuleName;
    string _mainModuleNameCamelCase;

public:
    NestJsMainFile():
        _mainModuleName("Main"),
        _mainModuleNameCamelCase(StringHelper::toLowerCaseFirstLetter(_mainModuleName)),
        NestJsProjectFile("main.ts.txt")
    {}
    NestJsMainFile(string moduleName):
        _mainModuleName(moduleName),
        _mainModuleNameCamelCase(StringHelper::toLowerCaseFirstLetter(moduleName)),
        NestJsProjectFile("main.ts.txt")
    {}
    virtual ~NestJsMainFile() {}

    void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = StringHelper::setVariableInText(MAIN_MODULE_NAME_VARIABLE_PATTERN, _mainModuleName, fileContent);
        fileContent = StringHelper::setVariableInText(MAIN_MODULE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _mainModuleNameCamelCase, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSMAINFILE_H
