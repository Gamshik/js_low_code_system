#ifndef MODULEFILE_H
#define MODULEFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class ModuleFile : public ProjectFile
{
public:
    ModuleFile(): ProjectFile("app.module.ts.txt") {}
    virtual ~ModuleFile() {}
};

#endif // MODULEFILE_H
