#ifndef NESTCLICONFIGFILE_H
#define NESTCLICONFIGFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class NestCliConfigFile : public ProjectFile
{
private:
    const string ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    string _rootDir;

public:
    NestCliConfigFile(string rootDir): ProjectFile("nest-cli.json.txt")
    {
        _rootDir = rootDir;
    }
    virtual ~NestCliConfigFile() {}

    void createFile(string path)
    {
        string fileContent = readFile(INSTANCE_FILE_PATH);

        fileContent = setVariableInText(ROOT_DIR_VARIABLE_PATTERN, _rootDir, fileContent);

        createProjFile(path, fileContent);
    }
};

#endif // NESTCLICONFIGFILE_H
