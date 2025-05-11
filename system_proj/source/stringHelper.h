#ifndef STRINGHELPER_H
#define STRINGHELPER_H

class StringHelper
{
public:
    StringHelper() = delete;

    static char* set_variable_in_text(char* pattern, char* value, char* text);
    static char* to_lower_case_first_letter(char* word);
};

#endif // STRINGHELPER_H
