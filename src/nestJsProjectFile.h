#ifndef NESTJSPROJECTFILE_H
#define NESTJSPROJECTFILE_H

#include <QString>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <fileSystemProvider.h>

using namespace std;
namespace fs = std::filesystem;

class NestJsProjectFile
{
private:
    QString strToQString(string str)
    {
        return QString::fromStdString(str);
    }

protected:
    const string INSTANCES_DIR_PATH = "../../../file_instances/";
    const string INSTANCE_FILE_PATH;

    string setVariableInText(string varPattern, string varValue, string txt)
    {
        QString pattern = strToQString(varPattern);

        QString qTxt = strToQString(txt);

        qTxt.replace(pattern, strToQString(varValue));

        return qTxt.toStdString();
    }

public:
    NestJsProjectFile(const string &instanceFilePath): INSTANCE_FILE_PATH(INSTANCES_DIR_PATH + instanceFilePath) {}
    virtual ~NestJsProjectFile() {}

    virtual void createFile(string path)
    {
        string fileContent = FileSystemProvider::readFile(INSTANCE_FILE_PATH);

        FileSystemProvider::createFile(path, fileContent);
    }
};

#endif // NESTJSPROJECTFILE_H
