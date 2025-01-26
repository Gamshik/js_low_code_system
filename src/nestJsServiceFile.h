#ifndef NESTJSSERVICEFILE_H
#define NESTJSSERVICEFILE_H

#include "iostream"

#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"
#include "stringHelper.h"

using namespace std;

class NestJsServiceFile : public NestJsProjectFile
{
private:
    const string NAME_VARIABLE_PATTERN = "{serviceName}";

    string _name;

public:
    NestJsServiceFile(string name):
        _name(name),
        NestJsProjectFile("service.ts.txt")
    {}
    virtual ~NestJsServiceFile() {}

    void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = StringHelper::setVariableInText(NAME_VARIABLE_PATTERN, _name, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSSERVICEFILE_H
