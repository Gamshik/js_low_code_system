#ifndef NESTJSPACKAGEFILE_H
#define NESTJSPACKAGEFILE_H

#include <nestJsProjectFile.h>

#include <iostream>

using namespace std;

class NestJsPackageFile : public NestJsProjectFile
{
private:
    const string PROJ_NAME_VARIABLE_PATTERN = "{projName}";
    const string ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    string _projName;
    string _rootDir;

public:
    NestJsPackageFile(string projName, string rootDir):
        NestJsProjectFile("package.json.txt"),
        _projName(projName),
        _rootDir(rootDir)
    {}
    virtual ~NestJsPackageFile() {}

    void createFile(string path)
    {
        string fileContent = readFile(INSTANCE_FILE_PATH);

        fileContent = setVariableInText(PROJ_NAME_VARIABLE_PATTERN, _projName, fileContent);
        fileContent = setVariableInText(ROOT_DIR_VARIABLE_PATTERN, _rootDir, fileContent);

        createProjFile(path, fileContent);
    }
};

#endif // NESTJSPACKAGEFILE_H
