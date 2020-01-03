//
//  c_wangers_string.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef CSTRING_H_
#define CSTRING_H_
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static unsigned int hexval_tbl[256] = {
        64, 64, 64, 64, 64, 64, 64, 64, 64, 32, 16, 64, 64, 16, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        32, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 64, 64, 64, 64, 64, 64,
        64, 10, 11, 12, 13, 14, 15, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
        64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
};

/**
 * pad_left:
 * @length: (type int) The length of the string after padding.
 * @pad: (type char) A single character to pad with
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Left pads a string to the desired length with the desired character.  If the input string
 * is equal to or longer than the required length of the padded string then the returned
 * string will be equal to the input string. The string will not be trimmed.
 *
 * Returns: char*
 */
char* pad_left(int length, char pad, char* input_string);

/**
 * pad_right:
 * @length: (type int) The length of the string after padding.
 * @pad: (type char) A single character to pad with
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Right pads a string to the desired length with the desired character.  If the input string
 * is equal to or longer than the required length of the padded string then the returned
 * string will be equal to the input string. The string will not be trimmed.
 *
 * Returns: char*
 */
char* pad_right(int length, char pad, char* input_string);

/**
 * pad_thai:
 * Tasty
 */

/**
 * lowercase_string:
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Converts a string to be entirely lowercase.
 *
 * Returns: char*
 */
char* lowercase_string(char* input_string);

/**
 * uppercase_string:
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Converts a string to be entirely uppercase.
 *
 * Returns: char*
 */
char* uppercase_string(char* input_string);

/**
 * last_word_in_string:
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Returns the last word from a string.
 *
 * Returns: char*
 */
char* last_word_in_string(char* input_string);

/**
 * remove_string_from_string:
 * @input_string: (type char*) A string to be processed.
 * @string_to_remove: (type char*) The string to be removed.
 *
 * @input_string must not be %NULL.
 * @string_to_remove must not be %NULL.
 *
 * Removes the provided string from the input string.
 *
 * Returns: char*
 */
char* remove_string_from_string(char* input_string, char* string_to_remove);

/**
 * replace_occurences_in_string:
 * @input_string: (type char*) A string to be processed.
 * @string_to_replace: (type char*) The string to be replaced.
 * @replacement_string: (type char*) The string which will replace the string to be replaced.
 *
 * @input_string must not be %NULL.
 * @string_to_replace must not be %NULL.
 * @replacement_string must not be %NULL.
 *
 * Replaces the one string with another within the input string.
 *
 * Returns: char*
 */
char* replace_occurences_in_string(char *input_string, const char *string_to_replace, const char *replacement_string);

/**
 * delimited_substring:
 * @input_string: (type char*) A string to be processed.
 * @opening_delimiter: (type char) The opening delimiter.
 * @closing_delimiter: (type char) The closing delimiter.
 *
 * @input_string must not be %NULL.
 * @opening_delimiter must not be %NULL.
 * @closing_delimiter must not be %NULL.
 *
 * Returns the first occurrence of the string within the provided delimiters.
 * Note - will not process nested delimiters correctly
 *
 * Returns: char*
 */
char* delimited_substring(char* input_string, char opening_delimiter, char closing_delimiter);

/**
 * trim:
 * @input_string: (type char*) A string to be processed.
 *
 * @input_string must not be %NULL.
 *
 * Remove whitespace from the end of the provided string
 *
 * Returns: void
 */
void trim(char *input_string);

/**
 * quoted_printable_decode:
 * @input_string: (type char*) A string to be processed.
 * @length: (type size_t) The length of the string to be processed.
 * @return_length: (type size_t*) The length of the string to be returned.
 *
 * @input_string must not be %NULL.
 * @length must not be %NULL.
 * @return_length must not be %NULL.
 *
 * Decode a quoted printable string
 *
 * Returns: unsigned char*
 */
unsigned char* quoted_printable_decode(const unsigned char *input_string, size_t length, size_t *return_length, int replace_us_by_ws);

bool starts_with(char* input_string, char* check_string);

#endif
