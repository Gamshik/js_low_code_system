#ifndef NESTJSCONTROLLERFILE_H
#define NESTJSCONTROLLERFILE_H

#include <nestJsProjectFile.h>

#include <iostream>

using namespace std;

class NestJsControllerFile : public NestJsProjectFile
{
public:
    NestJsControllerFile(): NestJsProjectFile("controller.ts.txt") {}
    virtual ~NestJsControllerFile() {}
};

#endif // NESTJSCONTROLLERFILE_H
