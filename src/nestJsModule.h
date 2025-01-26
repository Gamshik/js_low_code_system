#ifndef NESTJSMODULE_H
#define NESTJSMODULE_H

#include "nestJsServiceFile.h"
#include "nestJsControllerFile.h"
#include "nestJsModuleFile.h"
#include "stringHelper.h"

#include "iostream"

using namespace std;

class NestJsModule
{
private:
    NestJsServiceFile *_serviceFile;
    NestJsControllerFile *_controllerFile;
    NestJsModuleFile *_moduleFile;

    string _name;
    string _projRootDirPath;

    string _serviceFilePath;
    string _controllerFilePath;
    string _moduleFilePath;

public:
    NestJsModule():
        _name(""),
        _projRootDirPath("")
    {}
    NestJsModule(string name, string projRootDirPath):
        _serviceFile(new NestJsServiceFile(name)),
        _controllerFile(new NestJsControllerFile(name, name)),
        _moduleFile(new NestJsModuleFile(name)),
        _name(name),
        _projRootDirPath(projRootDirPath)
    {
        string nameCamelCase = StringHelper::toLowerCaseFirstLetter(_name);
        string moduleDir = _projRootDirPath + "/modules/" + nameCamelCase + "/";

        _serviceFilePath = moduleDir + nameCamelCase + ".service.ts";
        _controllerFilePath = moduleDir + nameCamelCase + ".controller.ts";
        _moduleFilePath = moduleDir + nameCamelCase + ".module.ts";
    }
    virtual ~NestJsModule()
    {
        delete _serviceFile;
        delete _controllerFile;
        delete _moduleFile;
    }

    void createModule()
    {
        _serviceFile->createFile(_serviceFilePath);
        _controllerFile->createFile(_controllerFilePath);
        _moduleFile->createFile(_moduleFilePath);
    }
};

#endif // NESTJSMODULE_H
