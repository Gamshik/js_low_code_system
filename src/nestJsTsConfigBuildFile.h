#ifndef NESTJSTSCONFIGBUILDFILE_H
#define NESTJSTSCONFIGBUILDFILE_H

#include <nestJsProjectFile.h>

#include <iostream>

using namespace std;

class NestJsTsConfigBuildFile : public NestJsProjectFile
{
public:
    NestJsTsConfigBuildFile(): NestJsProjectFile("tsconfig.build.json.txt") {}
    virtual ~NestJsTsConfigBuildFile() {}
};

#endif // NESTJSTSCONFIGBUILDFILE_H
