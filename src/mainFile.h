#ifndef MAINFILE_H
#define MAINFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class MainFile : public ProjectFile
{
public:
    MainFile(): ProjectFile("main.ts.txt") {}
    virtual ~MainFile() {}
};

#endif // MAINFILE_H
