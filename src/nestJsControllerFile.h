#ifndef NESTJSCONTROLLERFILE_H
#define NESTJSCONTROLLERFILE_H


#include "iostream"

#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

using namespace std;

class NestJsControllerFile : public NestJsProjectFile
{
private:
    const string NAME_VARIABLE_PATTERN = "{controllerName}";
    const string SERVICE_NAME_VARIABLE_PATTERN = "{serviceName}";
    const string SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN = "{serviceNameCamelCase}";

    string _name;
    string _serviceName;
    string _serviceNameCamelCase;

public:
    NestJsControllerFile(string name, string serviceName):
        _name(name),
        _serviceName(serviceName),
        _serviceNameCamelCase(StringHelper::toLowerCaseFirstLetter(serviceName)),
        NestJsProjectFile("controller.ts.txt")
    {}
    virtual ~NestJsControllerFile() {}

    void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = StringHelper::setVariableInText(NAME_VARIABLE_PATTERN, _name, fileContent);
        fileContent = StringHelper::setVariableInText(SERVICE_NAME_VARIABLE_PATTERN, _serviceName, fileContent);
        fileContent = StringHelper::setVariableInText(SERVICE_NAME_CAMEL_CASE_VARIABLE_PATTERN, _serviceNameCamelCase, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSCONTROLLERFILE_H
