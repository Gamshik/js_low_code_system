#ifndef CONTROLLERFILE_H
#define CONTROLLERFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class ControllerFile : public ProjectFile
{
public:
    ControllerFile(): ProjectFile("app.controller.ts.txt") {}
    virtual ~ControllerFile() {}
};

#endif // CONTROLLERFILE_H
