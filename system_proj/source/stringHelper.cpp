#include "stringHelper.h"

#include <iostream>
#include <string.h>

using namespace std;


char* StringHelper::set_variable_in_text(char* pattern, char* value, char* text)
{
    char* result = new char[1];
    result[0] = '\0';

    size_t text_length = strlen(text);
    size_t pattern_length = strlen(pattern);
    size_t value_length = strlen(value);

    int current_text_offset = 0, count_patterns = 0, i = 0;

    for (char* symbol = text; *symbol; symbol++, i++) {
        if (*symbol == pattern[0]) {
            bool is_pattern = true;
            int start_pattern_index = i;

            for (char* pattern_symbol = pattern; *pattern_symbol && is_pattern; pattern_symbol++, symbol++, i++) {
                if (*symbol != *pattern_symbol)
                    is_pattern = false;
                if (*pattern_symbol == pattern[pattern_length - 1])
                    break;
            }

            if (is_pattern) {
                char* old = result;

                int current_result_lenth = strlen(result);
                int count_symbols_between_patterns = start_pattern_index - current_text_offset;

                size_t new_result_size = current_result_lenth + count_symbols_between_patterns + value_length + 1;

                result = new char[new_result_size];

                memcpy(result, old, current_result_lenth);
                memcpy(&result[current_result_lenth], &text[current_text_offset], count_symbols_between_patterns);
                memcpy(&result[current_result_lenth + count_symbols_between_patterns], value, value_length);

                result[new_result_size - 1] = '\0';

                current_text_offset = start_pattern_index + pattern_length;
                count_patterns++;
                delete[] old;
            }
        }
        else if (i == text_length - 1) {
            char* old = result;

            int current_result_lenth = strlen(result);
            int count_remaining_symbols = text_length - current_text_offset;

            size_t new_result_size = current_result_lenth + count_remaining_symbols + 1;

            result = new char[new_result_size];

            memcpy(result, old, current_result_lenth);
            memcpy(&result[current_result_lenth], &text[current_text_offset], count_remaining_symbols);

            result[new_result_size - 1] = '\0';
            delete[] old;
        }
    }


    return result;
}

char* StringHelper::to_lower_case_first_letter(char* word)
{
    word[0] = std::tolower((unsigned char)word[0]);

    return word;
}
