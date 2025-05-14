#ifndef NESTJSTSCONFIGBUILDFILE_H
#define NESTJSTSCONFIGBUILDFILE_H

#include "nestJsProjectFile.h"

class NestJsTsConfigBuildFile : public NestJsProjectFile
{
public:
    NestJsTsConfigBuildFile(): NestJsProjectFile("tsconfig.build.json.txt") {}
    virtual ~NestJsTsConfigBuildFile() {}
};

#endif // NESTJSTSCONFIGBUILDFILE_H
