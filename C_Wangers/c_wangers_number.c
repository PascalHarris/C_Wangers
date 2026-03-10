#include "c_wangers_number.h"

#include <string.h> // only needed for debug purposes

float RaiseToPower(float x,float y) {
    if(y==0) {
        return 1;
    } else {
        return (x * pow(x, y - 1));
    }
}

bool is_a_number(char* input_string) {
    return (strspn(input_string, "0123456789") == strlen(input_string));
}

bool is_a_hex_number(char* input_string) {
    return (strspn(lowercase_string(input_string), "x0123456789abcdef() ") == strlen(input_string));
}

int bytesNeeded(long long input_number) {
    int bytes = 0;
    do {
        input_number >>= 8;
        bytes++;
    } while (input_number);
    return bytes;
}

bool bool_from_string(char* input_string) {
    char* compare_text = lowercase_string(input_string);
#define NUMBER_OF_STRINGS 4
    char truth_strings[NUMBER_OF_STRINGS][6] = {"yes", "true", "1", "on"};
    int i = 0;
    bool is_true = false;
    while (i < NUMBER_OF_STRINGS) {
        is_true = (strcmp(compare_text, truth_strings[i++]) == 0)?true:is_true;
    }
    return is_true;
}