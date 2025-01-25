#ifndef NESTJSMAINFILE_H
#define NESTJSMAINFILE_H

#include <nestJsProjectFile.h>

#include <iostream>

using namespace std;

class NestJsMainFile : public NestJsProjectFile
{
public:
    NestJsMainFile(): NestJsProjectFile("main.ts.txt") {}
    virtual ~NestJsMainFile() {}
};

#endif // NESTJSMAINFILE_H
