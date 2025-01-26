#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include "QString"

#include "iostream"

using namespace std;

class StringHelper
{
public:
    StringHelper() = delete;

    static QString strToQString(string str);
    static string setVariableInText(string varPattern, string varValue, string txt);
};

#endif // STRINGHELPER_H
