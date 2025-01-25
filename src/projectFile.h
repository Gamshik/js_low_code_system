#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <QString>

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class ProjectFile
{
private:
    QString strToQString(string str)
    {
        return QString::fromStdString(str);
    }

protected:
    const string INSTANCES_DIR_PATH = "../../../file_instances/";
    const string INSTANCE_FILE_PATH;

    string readFile(string path)
    {
        string fileContent;

        string contentLine;

        ifstream file(path);

        if (file.is_open())
        {
            while(getline(file, contentLine))
                fileContent += contentLine + '\n';
        }

        file.close();

        return fileContent;
    }
    void createProjFile(string path, string content)
    {
        createParentDirectoriesIfNotExist(path);

        ofstream file;

        file.open(path, ios::out);

        if (file.is_open())
            file << content;

        file.close();
    }
    void createParentDirectoriesIfNotExist(string path)
    {
        fs::path filePath(path);

        if (!filePath.parent_path().empty())
        {
            fs::create_directories(filePath.parent_path());
        }
    }
    string setVariableInText(string varPattern, string varValue, string txt)
    {
        QString pattern = strToQString(varPattern);

        QString qTxt = strToQString(txt);

        qTxt.replace(pattern, strToQString(varValue));

        return qTxt.toStdString();
    }

public:
    ProjectFile(const string &instanceFilePath): INSTANCE_FILE_PATH(INSTANCES_DIR_PATH + instanceFilePath) {}
    virtual ~ProjectFile() {}

    virtual void createFile(string path)
    {
        string fileContent = readFile(INSTANCE_FILE_PATH);

        createProjFile(path, fileContent);
    }
};

#endif // PROJECTFILE_H
