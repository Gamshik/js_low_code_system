#ifndef NESTJSPROJECTCREATOR_H
#define NESTJSPROJECTCREATOR_H

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <vector>

#include "nestJsPackageFile.h"
#include "nestJsTsConfigFile.h"
#include "nestJsTsConfigBuildFile.h"
#include "nestJsCliConfigFile.h"
#include "nestJsModule.h"
#include "nestJsMainFile.h"
#include "nestJsMainModuleFile.h"

class NestJsProjectCreator
{
private:
    NestJsPackageFile* _packageFile;
    NestJsTsConfigFile* _tsConfigFile;
    NestJsTsConfigBuildFile* _tsConfigBuildFile;
    NestJsCliConfigFile* _cliConfigFile;
    NestJsMainModuleFile* _mainModuleFile;
    NestJsMainFile* _mainFile;

    char* PACKAGE_FILE_PATH;
    char* TS_CONFIG_FILE_PATH;
    char* TS_CONFIG_BUILD_FILE_PATH;
    char* CLI_CONFIG_FILE_PATH;
    char* MAIN_MODULE_FILE_PATH;
    char* MAIN_FILE_PATH;

    vector<NestJsModule*> _modules;

    char* _projRootDirPath;

public:
    NestJsProjectCreator(const char* projPath, const char* projName, const char* rootDir = "src"):
        //PACKAGE_FILE_PATH(projPath + "/" + projName + "/package.json"),
        //TS_CONFIG_FILE_PATH(projPath + "/" + projName + "/tsconfig.json"),
        //TS_CONFIG_BUILD_FILE_PATH(projPath + "/" + projName + "/tsconfig.build.json"),
        //CLI_CONFIG_FILE_PATH(projPath + "/" + projName + "/nest-cli.json"),
        //MAIN_MODULE_FILE_PATH(projPath + "/" + projName + "/" + rootDir + "/main.module.ts"),
        //MAIN_FILE_PATH(projPath + "/" + projName + "/" + rootDir + "/main.ts"),
        //_packageFile(new NestJsPackageFile(projName, rootDir)),
        //_tsConfigFile(new NestJsTsConfigFile()),
        //_tsConfigBuildFile(new NestJsTsConfigBuildFile()),
        //_cliConfigFile(new NestJsCliConfigFile(rootDir)),
        //_mainFile(new NestJsMainFile()),
        //_mainModuleFile(new NestJsMainModuleFile("Main")),
        //_modules(0),
        //_projRootDirPath(projPath + "/" + projName + "/" + rootDir)
        _packageFile(nullptr), 
        _tsConfigFile(nullptr), 
        _tsConfigBuildFile(nullptr), 
        _cliConfigFile(nullptr), 
        _mainModuleFile(nullptr), 
        _mainFile(nullptr),
        _modules(0)
    {
        const char* slash = "\\";
        const char* package_suffix = "package.json";
        const char* tsconfig_suffix = "tsconfig.json";
        const char* tsconfig_build_suffix = "tsconfig.build.json";
        const char* cli_suffix = "nest-cli.json";
        const char* main_module_suffix = "main.module.ts";
        const char* main_suffix = "main.ts";

        size_t package_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(package_suffix) + 1;
        PACKAGE_FILE_PATH = (char*)malloc(package_path_len);

        PACKAGE_FILE_PATH[0] = '\0';
        strcat(PACKAGE_FILE_PATH, projPath);
        strcat(PACKAGE_FILE_PATH, slash);
        strcat(PACKAGE_FILE_PATH, projName);
        strcat(PACKAGE_FILE_PATH, slash);
        strcat(PACKAGE_FILE_PATH, package_suffix);

        // TS_CONFIG_FILE_PATH
        size_t tsconfig_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(tsconfig_suffix) + 1;
        TS_CONFIG_FILE_PATH = (char*)malloc(tsconfig_path_len);

        TS_CONFIG_FILE_PATH[0] = '\0';
        strcat(TS_CONFIG_FILE_PATH, projPath);
        strcat(TS_CONFIG_FILE_PATH, slash);
        strcat(TS_CONFIG_FILE_PATH, projName);
        strcat(TS_CONFIG_FILE_PATH, slash);
        strcat(TS_CONFIG_FILE_PATH, tsconfig_suffix);

        // TS_CONFIG_BUILD_FILE_PATH
        size_t tsconfig_build_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(tsconfig_build_suffix) + 1;
        TS_CONFIG_BUILD_FILE_PATH = (char*)malloc(tsconfig_build_path_len);

        TS_CONFIG_BUILD_FILE_PATH[0] = '\0';
        strcat(TS_CONFIG_BUILD_FILE_PATH, projPath);
        strcat(TS_CONFIG_BUILD_FILE_PATH, slash);
        strcat(TS_CONFIG_BUILD_FILE_PATH, projName);
        strcat(TS_CONFIG_BUILD_FILE_PATH, slash);
        strcat(TS_CONFIG_BUILD_FILE_PATH, tsconfig_build_suffix);

        // CLI_CONFIG_FILE_PATH
        size_t cli_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(cli_suffix) + 1;
        CLI_CONFIG_FILE_PATH = (char*)malloc(cli_path_len);

        CLI_CONFIG_FILE_PATH[0] = '\0';
        strcat(CLI_CONFIG_FILE_PATH, projPath);
        strcat(CLI_CONFIG_FILE_PATH, slash);
        strcat(CLI_CONFIG_FILE_PATH, projName);
        strcat(CLI_CONFIG_FILE_PATH, slash);
        strcat(CLI_CONFIG_FILE_PATH, cli_suffix);

        // MAIN_MODULE_FILE_PATH
        size_t main_module_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(rootDir) + strlen(slash) + strlen(main_module_suffix) + 1;
        MAIN_MODULE_FILE_PATH = (char*)malloc(main_module_path_len);

        MAIN_MODULE_FILE_PATH[0] = '\0';
        strcat(MAIN_MODULE_FILE_PATH, projPath);
        strcat(MAIN_MODULE_FILE_PATH, slash);
        strcat(MAIN_MODULE_FILE_PATH, projName);
        strcat(MAIN_MODULE_FILE_PATH, slash);
        strcat(MAIN_MODULE_FILE_PATH, rootDir);
        strcat(MAIN_MODULE_FILE_PATH, slash);
        strcat(MAIN_MODULE_FILE_PATH, main_module_suffix);

        // MAIN_FILE_PATH
        size_t main_path_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(rootDir) + strlen(slash) + strlen(main_suffix) + 1;
        MAIN_FILE_PATH = (char*)malloc(main_path_len);

        MAIN_FILE_PATH[0] = '\0';
        strcat(MAIN_FILE_PATH, projPath);
        strcat(MAIN_FILE_PATH, slash);
        strcat(MAIN_FILE_PATH, projName);
        strcat(MAIN_FILE_PATH, slash);
        strcat(MAIN_FILE_PATH, rootDir);
        strcat(MAIN_FILE_PATH, slash);
        strcat(MAIN_FILE_PATH, main_suffix);

        // _projRootDirPath
        size_t proj_root_len = strlen(projPath) + strlen(slash) + strlen(projName) + strlen(slash) + strlen(rootDir) + 1;
        _projRootDirPath = (char*)malloc(proj_root_len);
        
        _projRootDirPath[0] = '\0';
        strcat(_projRootDirPath, projPath);
        strcat(_projRootDirPath, slash);
        strcat(_projRootDirPath, projName);
        strcat(_projRootDirPath, slash);
        strcat(_projRootDirPath, rootDir);

        _packageFile = new NestJsPackageFile(projName, rootDir);
        _tsConfigFile = new NestJsTsConfigFile();
        _tsConfigBuildFile = new NestJsTsConfigBuildFile();
        _cliConfigFile = new NestJsCliConfigFile(StringHelper::Duplicate_String(rootDir));
        _mainFile = new NestJsMainFile();
        _mainModuleFile = new NestJsMainModuleFile("Main");
    }
    virtual ~NestJsProjectCreator()
    {
        delete _packageFile;
        delete _tsConfigFile;
        delete _tsConfigBuildFile;
        delete _cliConfigFile;
        delete _mainFile;
        delete _mainModuleFile;

        free(PACKAGE_FILE_PATH);
        free(TS_CONFIG_FILE_PATH);
        free(TS_CONFIG_BUILD_FILE_PATH);
        free(CLI_CONFIG_FILE_PATH);
        free(MAIN_MODULE_FILE_PATH);
        free(MAIN_FILE_PATH);
        free(_projRootDirPath);
    }

    void addModule(const char* name)
    {
        _modules.push_back(new NestJsModule(name, _projRootDirPath));
        _mainModuleFile->addModule(name);
    }
    void createProject()
    {
        _packageFile->createFile(PACKAGE_FILE_PATH);
        _tsConfigFile->createFile(TS_CONFIG_FILE_PATH);
        _tsConfigBuildFile->createFile(TS_CONFIG_BUILD_FILE_PATH);
        _cliConfigFile->createFile(CLI_CONFIG_FILE_PATH);
        _mainModuleFile->createFile(MAIN_MODULE_FILE_PATH);
        _mainFile->createFile(MAIN_FILE_PATH);

        for (NestJsModule *item : _modules)
            item->createModule();
    }
};

#endif // NESTJSPROJECTCREATOR_H
