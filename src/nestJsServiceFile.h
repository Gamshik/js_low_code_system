#ifndef NESTJSSERVICEFILE_H
#define NESTJSSERVICEFILE_H

#include "iostream"

#include <iostream>

using namespace std;

class NestJsServiceFile : public NestJsProjectFile
{
public:
    NestJsServiceFile(): NestJsProjectFile("service.ts.txt") {}
    virtual ~NestJsServiceFile() {}
};

#endif // NESTJSSERVICEFILE_H
