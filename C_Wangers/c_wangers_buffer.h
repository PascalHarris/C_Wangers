//
//  c_wangers_buffer.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef CBUFFER_H_
#define CBUFFER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define B64_LINE_LENGTH 76
static char B64[64] = {
        'A','B','C','D','E','F','G',
        'H','I','J','K','L','M','N',
        'O','P','Q','R','S','T',
        'U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g',
        'h','i','j','k','l','m','n',
        'o','p','q','r','s','t',
        'u','v','w','x','y','z',
        '0','1','2','3','4','5','6',
        '7','8','9','+','/'
};

/**
 @brief Swaps the byte order of a 64-bit unsigned integer.
 @discussion
 Converts between little-endian and big-endian formats by reordering each byte.
 @param LongNumber The 64-bit value to swap.
 @return The byte-swapped 64-bit value.
 */
unsigned long ByteSwap64 (unsigned long LongNumber);

/**
 @brief Swaps the byte order of a 32-bit integer.
 @discussion
 Reorders each byte to reverse endianness.
 @param Number The 32-bit value to swap.
 @return The byte-swapped 32-bit value.
 */
int ByteSwap32 (int Number);

/**
 @brief Swaps the byte order of a 16-bit short.
 @discussion
 Reverses the two bytes for endian conversion.
 @param Number The 16-bit value to swap.
 @return The byte-swapped 16-bit value.
 */
short ByteSwap16 (short Number);

/**
 @brief Prints the hexadecimal and binary representation of a byte.
 @discussion
 Displays the hex value followed by its binary form (e.g. `3f 00111111`).
 @param byte The byte to display.
  */
void dumpbits(char byte);

/**
 @brief Reads a 16-bit unsigned integer from a byte buffer.
 @discussion
 Assumes little-endian byte order.
 @param ptr Pointer to the buffer.
 @return The 16-bit value.
 */
unsigned long readU16( const unsigned char* ptr );

/**
 @brief Reads a 32-bit unsigned integer from a byte buffer.
 @discussion
 Assumes little-endian byte order.
 @param ptr Pointer to the buffer.
 @return The 32-bit value.
 */
unsigned long readU32( const unsigned char* ptr );

/**
 @brief Writes a 16-bit unsigned integer to a byte buffer.
 @discussion
 Stores the value in little-endian format.
 @param ptr Pointer to the buffer.
 @param data The 16-bit value to write.
 */
void writeU16( unsigned char* ptr, unsigned long data );

/**
 @brief Writes a 32-bit unsigned integer to a byte buffer.
 @discussion
 Stores the value in little-endian format.
 @param ptr Pointer to the buffer.
 @param data The 32-bit value to write.
 */
void writeU32( unsigned char* ptr, unsigned long data );

/**
 @brief Converts a hex string to a byte buffer.
 @discussion
 Parses pairs of hex characters into bytes.

 ⚠️ Notes:
 - Caller must free the returned buffer.
 - `buffer_size` is set to the number of bytes parsed.

 @param string Hex string (e.g. `"4a6f"`).
 @param buffer_size Pointer to store output size.
 @return Byte buffer.
 */
unsigned char* buffer_from_hexstring(char* string, size_t* buffer_size);

/**
 @brief Converts a byte buffer to a hex string.
 @discussion
 Formats each byte as a two-digit hex value.

 ⚠️ Notes:
 - Caller must free the returned string.

 @param buffer Byte buffer.
 @param buffer_size Size of the buffer.
 @return Hex string.
 */
char* hexstring_from_buffer(unsigned char* buffer, size_t buffer_size);

/**
 @brief Reverses the byte order of a buffer.
 @discussion
 Swaps bytes in-place from front to back.
 @param input_bytes Pointer to the buffer.
 @param length Length of the buffer.
 @return Pointer to the modified buffer.
 */
void * swap_bytes(void *input_bytes, size_t length);

/**
 @brief Determines if a string contains non-printable characters.
 @discussion
 Checks for characters below ASCII 32 (excluding tab and newline).
 @param input_string The string to check.
 @param len Length of the string.
 @return true if base64 encoding is recommended; false otherwise.
 */
bool requires_base64_encoding(char *input_string, size_t len);

/**
 @brief Decodes a base64-encoded string.
 @discussion
 Converts 4-character blocks into 3-byte sequences.

 ⚠️ Notes:
 - Caller must free the returned string.
 - Assumes global `B64[]` lookup table is defined.

 @param s Base64 string.
 @return Decoded string.
 */
char *base64_decode(char *s);

/**
 @brief Encodes binary data into base64 format.
 @discussion
 Converts 3-byte blocks into 4-character base64 strings.
 Optionally inserts line breaks every `B64_LINE_LENGTH` characters.

 ⚠️ Notes:
 - Caller must free the returned string.
 - Assumes global `B64[]` and `B64_LINE_LENGTH` are defined.

 @param data Input binary data.
 @param input_length Length of input data.
 @param multiple_line Whether to insert line breaks.
 @return Base64-encoded string.
 */
char *base64_encode(unsigned char *data, size_t input_length, bool multiple_line);

#endif
