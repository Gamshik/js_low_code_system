#ifndef NESTJSTSCONFIGFILE_H
#define NESTJSTSCONFIGFILE_H

#include "nestJsProjectFile.h"

class NestJsTsConfigFile : public NestJsProjectFile
{
public:
    NestJsTsConfigFile(): NestJsProjectFile("tsconfig.json.txt") {}
    virtual ~NestJsTsConfigFile() {}
};

#endif // NESTJSTSCONFIGFILE_H
