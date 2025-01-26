#ifndef NESTJSMODULE_H
#define NESTJSMODULE_H

#include "nestJsServiceFile.h"
#include "nestJsControllerFile.h"
#include "nestJsModuleFile.h"

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
        _serviceFile(new NestJsServiceFile()),
        _controllerFile(new NestJsControllerFile()),
        _moduleFile(new NestJsModuleFile()),
        _name(name),
        _projRootDirPath(projRootDirPath)
    {
        string moduleDir = _projRootDirPath + "/modules/" + _name + "/";

        _serviceFilePath = moduleDir + _name + ".service.ts";
        _controllerFilePath = moduleDir + _name + ".controller.ts";
        _moduleFilePath = moduleDir + _name + ".module.ts";
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
