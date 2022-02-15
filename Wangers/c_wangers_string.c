#include "c_wangers_string.h"

char* pad_left(size_t length, char pad, char* input_string) {
    size_t minLength = length > strlen(input_string)?length:strlen(input_string);

    char* return_string = (char*)calloc(minLength, sizeof(char));
    size_t padLen = length - strlen(input_string);
    padLen = padLen < 0 ? 0 : padLen;

    memset(return_string, 0, sizeof(char));
    memset(return_string, pad, length);
    memcpy(return_string+padLen, input_string, minLength - padLen);

    return return_string;
}

char* pad_right(size_t length, char pad, char* input_string) {
    size_t minLength = length > strlen(input_string)?length:strlen(input_string);

    char* return_string = (char*)calloc(minLength, sizeof(char));
    size_t padLen = length - strlen(input_string);
    padLen = padLen < 0 ? 0 : padLen;

    memset(return_string, 0, sizeof(char));
    memset(return_string, pad, length);
    memcpy(return_string, input_string, minLength - padLen);

    return return_string;
}

char* lowercase_string(char* input_string) {
    char* return_string = input_string;
    int i = 0;
    while (return_string[i] != '\0') {
        if (return_string[i] >= 'A' && return_string[i] <= 'Z') { return_string[i] += 32; }
        i++;
    }
    return return_string;
}

char* uppercase_string(char* input_string) {
    char* return_string = input_string;
    int i = 0;
    while (return_string[i] != '\0') {
        if (return_string[i] >= 'a' && return_string[i] <= 'z') { return_string[i] -= 32; }
        i++;
    }
    return return_string;
}

char* last_word_in_string(char* input_string) {
    char *p = strrchr(input_string, ' ');
    if (p && *(p + 1)) {
        return p + 1;
    }
    return "";
}

char* remove_string_from_string(char* input_string, char* string_to_remove) {
    char *buffer, *return_string = malloc(strlen(input_string)+1);
    
    buffer = strtok(input_string, " \t\n");
    while(buffer) {
        if (strcmp(buffer, string_to_remove) != 0) {
//            strcat(return_string, buffer);
//            strcat(return_string, " ");
            strlcat(return_string, buffer, strlen(input_string)+1);
            strlcat(return_string, " ", strlen(input_string)+1);
        }
        buffer = strtok(NULL, " \t\n");
    }
    return return_string; // remember to free new_str!
}

char* replace_occurences_in_string(char *input_string, const char *string_to_replace, const char *replacement_string) {
    char* output_string = malloc(sizeof(char) * strlen(input_string));
    char *insert_point = &output_string[0];
    const char *tmp = input_string;
    size_t string_to_replace_len = strlen(string_to_replace);
    size_t replacement_string_len = strlen(replacement_string);

    while (1) {
        const char *p = strstr(tmp, string_to_replace);
        if (p == NULL) {
//            strcpy(insert_point, tmp);
            strlcpy(insert_point, tmp, strlen(insert_point));
            break;
        }

        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        if (strlen(replacement_string) > strlen(string_to_replace)) { // need a bigger buffer
            output_string = (char *)realloc(output_string, sizeof(char) * (strlen(output_string) + (strlen(replacement_string) - strlen(string_to_replace))));
        }
        memcpy(insert_point, replacement_string, replacement_string_len);
        insert_point += replacement_string_len;

        tmp = p + string_to_replace_len;
    }
    return output_string;
}

char* delimited_substring(char* input_string, char opening_delimiter, char closing_delimiter) {
    int i = 0, j, char_position = 0;
    char* output_string = malloc(sizeof(char)); // only need one character at the moment!
    while (input_string[i] != '\0') {
        if (input_string[i] == opening_delimiter) {
            j = i + 1;
            while (input_string[j] != closing_delimiter) {
                output_string = (char *)realloc(output_string, (char_position + 2)*sizeof(char));
                output_string[char_position] = input_string[j];
                char_position++;
                j++;
            }
            output_string[char_position] = '\0';
            return output_string;
        } else {
            i++;
        }
    }
    output_string[char_position] = '\0';
    return output_string;
}

void trim(char *input_string) {
    size_t i, begin = 0, end = strlen(input_string) - 1;
    while (isspace((unsigned char) input_string[begin])) { begin++; }
    while ((end >= begin) && isspace((unsigned char) input_string[end])) { end--; }
    for (i = begin; i <= end; i++) { input_string[i - begin] = input_string[i]; }
    input_string[i - begin] = '\0';
}

unsigned char* quoted_printable_decode(const unsigned char *input_string, size_t length, size_t *return_length, int replace_us_by_ws) {
    register unsigned const char *input_locn;
    register unsigned char *output_locn;
    register size_t i, high_nibble, low_nibble;

    size_t decoded_length, buffer_size;
    unsigned char *return_string;

    if (replace_us_by_ws) {
        replace_us_by_ws = '_';
    }

    i = length; input_locn = input_string; buffer_size = length;

    while (i > 1 && *input_locn != '\0') {
        if (*input_locn == '=') {
            buffer_size -= 2;
            input_locn++;
            i--;
        }
        input_locn++;
        i--;
    }

    return_string = (unsigned char*)malloc(buffer_size + 1);
    i = length; input_locn = input_string; output_locn = return_string;
    decoded_length = 0;

    while (i > 0 && *input_locn != '\0') {
        if (*input_locn == '=') {
            i--; input_locn++;
            if (i == 0 || *input_locn == '\0') {
                break;
            }
            high_nibble = hexval_tbl[*input_locn];
            if (high_nibble < 16) {
                /* next char should be a hexadecimal digit */
                if ((--i) == 0 || (low_nibble = hexval_tbl[*(++input_locn)]) >= 16) {
                    free(return_string);
                    return NULL;
                }
                *(output_locn++) = (high_nibble << 4) | low_nibble; decoded_length++;
                i--; input_locn++;
            } else if (high_nibble < 64) {
                /* soft line break */
                while (high_nibble == 32) {
                    if (--i == 0 || (high_nibble = hexval_tbl[*(++input_locn)]) == 64) {
                        free(return_string);
                        return NULL;
                    }
                }
                if (input_locn[0] == '\r' && i >= 2 && input_locn[1] == '\n') {
                    i--; input_locn++;
                }
                i--; input_locn++;
            } else {
                free(return_string);
                return NULL;
            }
        } else {
            *(output_locn++) = (replace_us_by_ws == *input_locn ? '\x20': *input_locn);
            i--; input_locn++; decoded_length++;
        }
    }

    *output_locn = '\0';
    *return_length = decoded_length;
    return return_string;
}

bool starts_with(char* input_string, char* check_string) {
    bool matches = true;
    int i = 0;
    
    if (strlen(check_string) > strlen(input_string)) { matches = false; }
    while (matches && i < strlen(check_string)) {
        if (input_string[i] != check_string[i]) { matches = false; }
        i++;
    }
    
    return matches;
}

/** compare strings case-insensitive.
 *  @return  -1 if a < b, 0 if a==b, 1 if a > b
 */
int case_insensitive_compare(char *a, char *b) {
    while(*a != '\0' && *b != '\0' && ((int)toupper(*a)==(int)toupper(*b))) {
        a++; b++;
    }
    if (toupper(*a) == toupper(*b)) {
        return 0;
    } else if (toupper(*a) < toupper(*b)) {
        return -1;
    } else {
        return 1;
    }
}

// compare upto x chars in string a and b case-insensitively
// returns -1 if a < b, 0 if a==b, 1 if a > b
int case_insensitive_compare_up_to_n_characters(char *a, char *b, size_t character_count) {
    size_t y = 0;
    while (*a != '\0' && *b != '\0' && y < character_count && toupper(*a)==toupper(*b)) {
        a++; b++; y++;
    }
    // if we have reached the end of either string, or a and b still match
    if (*a == '\0' || *b == '\0' || toupper(*a)==toupper(*b)) {
        return 0;
    } else if (toupper(*a) < toupper(*b)) {
        return -1;
    } else {
        return 1;
    }
}

int count_occurences_of_char(char *input_string, char check_char) {
    int count = 0;
    while (*input_string) {
        if (*input_string == check_char) {
            count++;
        }
        input_string++;
    }
    return count;
}
