#ifndef NESTJSMODULEFILE_H
#define NESTJSMODULEFILE_H

#include <nestJsProjectFile.h>

#include <iostream>

using namespace std;

class NestJsModuleFile : public NestJsProjectFile
{
public:
    NestJsModuleFile(): NestJsProjectFile("module.ts.txt") {}
    virtual ~NestJsModuleFile() {}
};

#endif // NESTJSMODULEFILE_H
