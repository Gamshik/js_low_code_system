#include "fileSystemProvider.h"

#include "iostream"
#include "fstream"
#include "filesystem"

using namespace std;
namespace fs = std::filesystem;

void FileSystemProvider::createParentDirectoriesIfNotExist(string path)
{
    fs::path filePath(path);

    if (!filePath.parent_path().empty())
    {
        fs::create_directories(filePath.parent_path());
    }
}

string FileSystemProvider::readFile(string path)
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

void FileSystemProvider::createFile(string path, string content)
{
    FileSystemProvider:createParentDirectoriesIfNotExist(path);

    ofstream file;

    file.open(path, ios::out);

    if (file.is_open())
        file << content;

    file.close();
}
