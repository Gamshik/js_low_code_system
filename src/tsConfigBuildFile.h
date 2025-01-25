#ifndef TSCONFIGBUILDFILE_H
#define TSCONFIGBUILDFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class TsConfigBuildFile : public ProjectFile
{
public:
    TsConfigBuildFile(): ProjectFile("tsconfig.build.json.txt") {}
    virtual ~TsConfigBuildFile() {}
};

#endif // TSCONFIGBUILDFILE_H
