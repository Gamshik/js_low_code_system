#ifndef NESTJSCLICONFIGFILE_H
#define NESTJSCLICONFIGFILE_H

#include "iostream"

#include "nestJsProjectFile.h"
#include "fileSystemProvider.h"

using namespace std;

class NestJsCliConfigFile : public NestJsProjectFile
{
private:
    const string ROOT_DIR_VARIABLE_PATTERN = "{rootDir}";

    string _rootDir;

public:
    NestJsCliConfigFile(string rootDir):
        NestJsProjectFile("nest-cli.json.txt"),
        _rootDir(rootDir)
    {}
    virtual ~NestJsCliConfigFile() {}

    void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        fileContent = setVariableInText(ROOT_DIR_VARIABLE_PATTERN, _rootDir, fileContent);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSCLICONFIGFILE_H
