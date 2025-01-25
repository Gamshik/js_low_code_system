#ifndef SERVICEFILE_H
#define SERVICEFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class ServiceFile : public ProjectFile
{
public:
    ServiceFile(): ProjectFile("app.service.ts.txt") {}
    virtual ~ServiceFile() {}
};

#endif // SERVICEFILE_H
