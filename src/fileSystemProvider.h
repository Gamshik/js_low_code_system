#ifndef FILESYSTEMPROVIDER_H
#define FILESYSTEMPROVIDER_H

#include "iostream"

using namespace std;

class FileSystemProvider
{
private:
    static void createParentDirectoriesIfNotExist(string path);

public:
    FileSystemProvider() = delete;

    static string readFile(string path);
    static void createFile(string path, string content);
};

#endif // FILESYSTEMPROVIDER_H
