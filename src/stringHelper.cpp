#include "stringHelper.h"

#include "QString"
#include "QChar"

#include "iostream"

using namespace std;

QChar StringHelper::charToQChar(char symbol)
{
    return QChar(symbol);
}

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

string StringHelper::toLowerCaseFirstLetter(string word)
{
    QString qWord = StringHelper::strToQString(word);
    QChar firstLetter = StringHelper::charToQChar(word[0]);

    qWord.replace(firstLetter, firstLetter.toLower());

    return qWord.toStdString();
}
