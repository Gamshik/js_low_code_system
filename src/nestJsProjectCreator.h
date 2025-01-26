#ifndef NESTJSPROJECTCREATOR_H
#define NESTJSPROJECTCREATOR_H

#include "nestJsPackageFile.h"
#include "nestJsTsConfigFile.h"
#include "nestJsTsConfigBuildFile.h"
#include "nestJsCliConfigFile.h"
#include "nestJsModule.h"
#include "nestJsMainFile.h"
#include "nestJsMainModuleFile.h"

#include "iostream"

using namespace std;

class NestJsProjectCreator
{
private:
    NestJsPackageFile *_packageFile;
    NestJsTsConfigFile *_tsConfigFile;
    NestJsTsConfigBuildFile *_tsConfigBuildFile;
    NestJsCliConfigFile *_cliConfigFile;
    NestJsMainModuleFile *_mainModuleFile;
    NestJsMainFile *_mainFile;

    const string PACKAGE_FILE_PATH;
    const string TS_CONFIF_FILE_PATH;
    const string TS_CONFIG_BUILD_FILE_PATH;
    const string CLI_CONFIG_FILE_PATH;
    const string MAIN_MODULE_FILE_PATH;
    const string MAIN_FILE_PATH;

    vector<NestJsModule*> _modules;

    string _projRootDirPath;

public:
    NestJsProjectCreator(string projPath, string projName, string rootDir = "src"):
        PACKAGE_FILE_PATH(projPath + "/" + projName + "/package.json"),
        TS_CONFIF_FILE_PATH(projPath + "/" + projName + "/tsconfig.json"),
        TS_CONFIG_BUILD_FILE_PATH(projPath + "/" + projName + "/tsconfig.build.json"),
        CLI_CONFIG_FILE_PATH(projPath + "/" + projName + "/nest-cli.json"),
        MAIN_MODULE_FILE_PATH(projPath + "/" + projName + "/" + rootDir + "/main.module.ts"),
        MAIN_FILE_PATH(projPath + "/" + projName + "/" + rootDir + "/main.ts"),
        _packageFile(new NestJsPackageFile(projName, rootDir)),
        _tsConfigFile(new NestJsTsConfigFile()),
        _tsConfigBuildFile(new NestJsTsConfigBuildFile()),
        _cliConfigFile(new NestJsCliConfigFile(rootDir)),
        _mainFile(new NestJsMainFile()),
        _mainModuleFile(new NestJsMainModuleFile("Main")),
        _modules(0),
        _projRootDirPath(projPath + "/" + projName + "/" + rootDir)
    {}
    virtual ~NestJsProjectCreator()
    {
        delete _packageFile;
        delete _tsConfigFile;
        delete _tsConfigBuildFile;
        delete _cliConfigFile;
        delete _mainFile;
        delete _mainModuleFile;
    }

    void addModule(string name)
    {
        _modules.push_back(new NestJsModule(name, _projRootDirPath));
        _mainModuleFile->addModule(name);
    }
    void createProject()
    {
        _packageFile->createFile(PACKAGE_FILE_PATH);
        _tsConfigFile->createFile(TS_CONFIF_FILE_PATH);
        _tsConfigBuildFile->createFile(TS_CONFIG_BUILD_FILE_PATH);
        _cliConfigFile->createFile(CLI_CONFIG_FILE_PATH);
        _mainModuleFile->createFile(MAIN_MODULE_FILE_PATH);
        _mainFile->createFile(MAIN_FILE_PATH);

        for (NestJsModule *item : _modules)
        {
            item->createModule();
        }
    }
};

#endif // NESTJSPROJECTCREATOR_H
