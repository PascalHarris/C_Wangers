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
 * ByteSwap64:
 * @LongNumber: (type unsigned long) An unsigned long number that will be processed.
 *
 * Performs a 64 bit bitwise endian swap. Necessary for Little Endian files.
 *
 * @see: ByteSwap32
 * @see: ByteSwap16
 * @see: SwapBytes
 *
 * Returns: unsigned long
 */
unsigned long ByteSwap64 (unsigned long LongNumber);

/**
 * ByteSwap32:
 * @Number: (type int) An int number that will be processed.
 *
 * Performs a 32 bit bitwise endian swap. Necessary for Little Endian files.
 *
 * @see: ByteSwap64
 * @see: ByteSwap16
 * @see: SwapBytes
 *
 * Returns: int
 */
int ByteSwap32 (int Number);

/**
 * ByteSwap16:
 * @Number: (type short) A short number that will be processed.
 *
 * Performs a 16 bit bitwise endian swap. Necessary for Little Endian files.
 *
 * @see: ByteSwap64
 * @see: ByteSwap32
 * @see: SwapBytes
 *
 * Returns: short
 */
short ByteSwap16 (short Number);

/**
 * dumpbits:
 * @byte: (type char) A byte that will be broken into its component bits.
 *
 * This is handy for debugging.  What bits are in those bytes? Easy enough to do with a calculator - but this way
 * you don't need to!
 *
 * Returns: void
 */
void dumpbits(char byte);

unsigned long readU16( const unsigned char* ptr );

unsigned long readU32( const unsigned char* ptr );

void writeU16( unsigned char* ptr, unsigned long data );

void writeU32( unsigned char* ptr, unsigned long data );

/**
 * buffer_from_hexstring:
 * @string: (type char*) The hexstring that will be converted to a databuffer.
 * @buffer_size: (type size_t*) A pointer to the size of the returned databuffer.
 *
 * Creates a databuffer from the provided string, returning the size through a pointer to the buffer_size.
 *
 * Returns: unsigned char*
 */
unsigned char* buffer_from_hexstring(char* string, size_t* buffer_size);

/**
 * hexstring_from_buffer:
 * @buffer: (type unsigned char*) A pointer to the databuffer that will be converted to a string.
 * @buffer_size: (type size_t) The size of the buffer which will be processed.
 *
 * Creates a string from the provided databuffer.
 *
 * Returns: char*
 */
char* hexstring_from_buffer(unsigned char* buffer, size_t buffer_size);

/**
 * swap_bytes:
 * @input_bytes: (type void*) A pointer to the databuffer that will be processed.
 * @length: (type size_t) The size of the buffer which will be processed.
 *
 * Reverses the order of the provided bytes.
 *
 * @see: ByteSwap64
 * @see: ByteSwap32
 * @see: ByteSwap16
 *
 * Returns: void*
 */
void * swap_bytes(void *input_bytes, size_t length);

/**
 * base64_decode:
 * @s: (type char*) The B64 encoded string to be decoded
 *
 * Decodes b64 encoded data into a buffer
 *
 * Returns: char*
 */
char *base64_decode(char *s);

#endif
