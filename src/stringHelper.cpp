#include "stringHelper.h"

#include "QString"

#include "iostream"

using namespace std;

QString StringHelper::strToQString(string str)
{
    return QString::fromStdString(str);
}

string StringHelper::setVariableInText(string varPattern, string varValue, string txt)
{
    QString pattern = StringHelper::strToQString(varPattern);

    QString qTxt = StringHelper::strToQString(txt);

    qTxt.replace(pattern, StringHelper::strToQString(varValue));

    return qTxt.toStdString();
}
