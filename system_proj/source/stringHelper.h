#ifndef STRINGHELPER_H
#define STRINGHELPER_H

class StringHelper
{
public:
    StringHelper() = delete;

    static char* Set_variable_in_text(const char* pattern, const char* value, const char* text);
    static char* To_lower_case_first_letter(const char* word);
    static char* Duplicate_String(const char* src);
};

#endif // STRINGHELPER_H
