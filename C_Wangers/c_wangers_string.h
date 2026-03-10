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
 @brief Pads a string on the left to a specified length.
 @discussion
 Allocates a new string and fills it with `pad` characters on the left.
 Copies the original string to the right-aligned position.

 ⚠️ Notes:
 - Caller must free the returned string.
 - If `length` is less than input length, returns a copy of the input.

 @param length Desired total length.
 @param pad Padding character.
 @param input_string Input string to pad.
 @return Left-padded string.
 */
char* pad_left(size_t length, char pad, char* input_string);

/**
 @brief Pads a string on the right to a specified length.
 @discussion
 Allocates a new string and fills it with `pad` characters on the right.
 Copies the original string to the left-aligned position.

 ⚠️ Notes:
 - Caller must free the returned string.
 - If `length` is less than input length, returns a copy of the input.

 @param length Desired total length.
 @param pad Padding character.
 @param input_string Input string to pad.
 @return Right-padded string.
 */
char* pad_right(size_t length, char pad, char* input_string);

/**
 @brief Converts a string to lowercase in-place.
 @discussion
 Iterates through each character and converts uppercase letters to lowercase.

 ⚠️ Notes:
 - Modifies the original string.
 - Assumes ASCII encoding.

 @param input_string The string to convert.
 @return The modified input string.
 */
char* lowercase_string(char* input_string);

/**
 @brief Converts a string to uppercase in-place.
 @discussion
 Iterates through each character and converts lowercase letters to uppercase.

 ⚠️ Notes:
 - Modifies the original string.
 - Assumes ASCII encoding.

 @param input_string The string to convert.
 @return The modified input string.
 */
char* uppercase_string(char* input_string);

/**
 @brief Extracts the last word from a space-delimited string.
 @discussion
 Finds the last space and returns the substring after it.

 @param input_string The input string.
 @return Pointer to the last word or empty string if none found.
 */
char* last_word_in_string(char* input_string);

/**
 @brief Removes all occurrences of a specific word from a string.
 @discussion
 Tokenizes the input and rebuilds a new string excluding the target word.

 ⚠️ Notes:
 - Modifies `input_string` via `strtok`.
 - Caller must free the returned string.

 @param input_string The input string.
 @param string_to_remove The word to remove.
 @return A new string with the word removed.
 */
char* remove_string_from_string(char* input_string, char* string_to_remove);

/**
 @brief Replaces all occurrences of a substring with another.
 @discussion
 Iteratively searches and replaces each match, reallocating buffer as needed.

 ⚠️ Notes:
 - Caller must free the returned string.
 - May over-allocate or under-allocate if replacement length varies.

 @param input_string The input string.
 @param string_to_replace Substring to replace.
 @param replacement_string Replacement value.
 @return A new string with replacements applied.
 */
char* replace_occurences_in_string(char *input_string, const char *string_to_replace, const char *replacement_string);

/**
 @brief Extracts a substring between two delimiters.
 @discussion
 Searches for the first pair of delimiters and returns the enclosed content.

 ⚠️ Notes:
 - Caller must free the returned string.
 - Returns empty string if delimiters not found.

 @param input_string The input string.
 @param opening_delimiter Start delimiter.
 @param closing_delimiter End delimiter.
 @return Extracted substring.
 */
char* delimited_substring(char* input_string, char opening_delimiter, char closing_delimiter);

/**
 @brief Trims leading and trailing whitespace from a string.
 @discussion
 Modifies the string in-place by shifting characters.
 @param input_string The string to trim.
 */
void trim(char *input_string);

/**
 @brief Decodes a quoted-printable encoded string.
 @discussion
 Handles hex decoding, soft line breaks, and optional underscore replacement.

 ⚠️ Notes:
 - Caller must free the returned buffer.
 - Returns NULL on malformed input.

 @param input_string Encoded input.
 @param length Length of input.
 @param return_length Pointer to store decoded length.
 @param replace_us_by_ws If true, replaces underscores with spaces.
 @return Decoded string or NULL.
 */
unsigned char* quoted_printable_decode(const unsigned char *input_string, size_t length, size_t *return_length, int replace_us_by_ws);

/**
 @brief Checks if a string starts with a given prefix.
 @discussion
 Compares characters sequentially.

 @param input_string The full string.
 @param check_string The prefix to check.
 @return true if input starts with prefix; false otherwise.
 */
bool starts_with(char* input_string, char* check_string);

/**
 @brief Compares two strings case-insensitively.
 @discussion
 Returns:
 - `0` if equal
 - `-1` if `a < b`
 - `1` if `a > b`

 @param a First string.
 @param b Second string.
 @return Comparison result.
 */
int case_insensitive_compare(char *a, char *b);

/**
 @brief Compares two strings case-insensitively up to `character_count` characters.
 @discussion
 Returns:
 - `0` if equal
 - `-1` if `a < b`
 - `1` if `a > b`

 @param a First string.
 @param b Second string.
 @param character_count Number of characters to compare.
 @return Comparison result.
 */
int case_insensitive_compare_up_to_n_characters(char *a, char *b, size_t character_count);

/**
 @brief Counts the number of times a character appears in a string.
 @discussion
 Iterates through the string and increments a counter on match.

 @param input_string The string to search.
 @param check_char The character to count.
 @return Number of occurrences.
 */
int count_occurences_of_char(char *input_string, char check_char);

#endif
