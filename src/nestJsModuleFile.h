#ifndef NESTJSMODULEFILE_H
#define NESTJSMODULEFILE_H

#include "nestJsProjectFile.h"
#include "stringHelper.h"

#include "iostream"

using namespace std;

class NestJsModuleFile : public NestJsProjectFile
{
private:
    const string NAME_VARIABLE_PATTERN = "{moduleName}";
    const string SERVICE_NAME_VARIABLE_PATTERN = "{serviceName}";
    const string CONTROLLER_NAME_VARIABLE_PATTERN = "{controllerName}";
    const string SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{serviceNameCamelCase}";
    const string CONTROLLER_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{controllerNameCamelCase}";

    string _name;
    string _serviceName;
    string _controllerName;
    string _serviceNameCamelCase;
    string _controllerNameCamelCase;

public:
    NestJsModuleFile(string name):
        _name(name),
        _serviceName(name),
        _controllerName(name),
        _serviceNameCamelCase(StringHelper::toLowerCaseFirstLetter(name)),
        _controllerNameCamelCase(StringHelper::toLowerCaseFirstLetter(name)),
        NestJsProjectFile("module.ts.txt")
    {}
    NestJsModuleFile(string name, string serviceName, string controllerName):
        _name(name),
        _serviceName(serviceName),
        _controllerName(controllerName),
        _serviceNameCamelCase(StringHelper::toLowerCaseFirstLetter(serviceName)),
        _controllerNameCamelCase(StringHelper::toLowerCaseFirstLetter(controllerName)),
        NestJsProjectFile("module.ts.txt")
    {}
    virtual ~NestJsModuleFile() {}

    void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = StringHelper::setVariableInText(NAME_VARIABLE_PATTERN, _name, fileContent);
        fileContent = StringHelper::setVariableInText(SERVICE_NAME_VARIABLE_PATTERN, _serviceName, fileContent);
        fileContent = StringHelper::setVariableInText(CONTROLLER_NAME_VARIABLE_PATTERN, _controllerName, fileContent);
        fileContent = StringHelper::setVariableInText(SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _serviceNameCamelCase, fileContent);
        fileContent = StringHelper::setVariableInText(CONTROLLER_NAME_CAMEL_CASE_VARIABLE_PATTERN, _controllerNameCamelCase, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSMODULEFILE_H
