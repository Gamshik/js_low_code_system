#ifndef TSCONFIGFILE_H
#define TSCONFIGFILE_H

#include <projectFile.h>

#include <iostream>

using namespace std;

class TsConfigFile : public ProjectFile
{
public:
    TsConfigFile(): ProjectFile("tsconfig.json.txt") {}
    virtual ~TsConfigFile() {}
};

#endif // TSCONFIGFILE_H
