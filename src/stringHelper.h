#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include "QString"
#include "QChar"

#include "iostream"

using namespace std;

class StringHelper
{
public:
    StringHelper() = delete;

    static QString strToQString(string str);
    static QChar charToQChar(char symbol);
    static string setVariableInText(string varPattern, string varValue, string txt);
    static string toLowerCaseFirstLetter(string word);
};

#endif // STRINGHELPER_H
