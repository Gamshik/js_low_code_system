#ifndef PACKAGEJSONFILE_H
#define PACKAGEJSONFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class PackageJsonFile : public ProjectFile
{
private:
    const string PROJ_NAME_VARIABLE_PATTERN = "{projName}";
    const string ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    string _projName;
    string _rootDir;

public:
    PackageJsonFile(string projName, string rootDir): ProjectFile("package.json.txt")
    {
        _projName = projName;
        _rootDir = rootDir;
    }
    virtual ~PackageJsonFile() {}

    void createFile(string path)
    {
        string fileContent = readFile(INSTANCE_FILE_PATH);

        fileContent = setVariableInText(PROJ_NAME_VARIABLE_PATTERN, _projName, fileContent);
        fileContent = setVariableInText(ROOT_DIR_VARIABLE_PATTERN, _rootDir, fileContent);

        createProjFile(path, fileContent);
    }
};

#endif // PACKAGEJSONFILE_H
