//
//  c_wangers_number.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef CNUMBER_H_
#define CNUMBER_H_
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "c_wangers_string.h"

//#define MIN(a,b) (((a)<(b))?(a):(b))
//#define MAX(a,b) (((a)>(b))?(a):(b))

/**
 * is_a_number:
 * @x: (type float) the number to be raised.
 * @y: (type float) the exponent.
 *
 * Raise x to the Power y
 *
 * Returns: float
 */
float RaiseToPower(float x,float y);

/**
 * is_a_number:
 * @input_string: (type char*) A string which requires validation.
 *
 * Checks to see whether the provided string is a number or not.  Returns true if it is.
 *
 * Returns: bool
 */
bool is_a_number(char* input_string);

/**
 * is_a_hex_number:
 * @input_string: (type char*) A string which requires validation.
 *
 * Checks to see whether the provided string is a hexadecimal number or not.  Returns true if it is.
 *
 * Returns: bool
 */
bool is_a_hex_number(char* input_string);

/**
 * bytesNeeded:
 * @input_number: (type long long) A number which requires validation.
 *
 * Calculates the number of bytes required to store a number.
 *
 * Returns: int
 */
int bytesNeeded(long long input_number);

/**
 * bool_from_string:
 * @input_string: (type char*) A string to be converted into a boolean value.
 *
 * Converts a string into a boolean value. "yes", "true", "1", "on" are true
 * All other values are false. Case insensitive.
 *
 * Returns: bool
 */
bool bool_from_string(char* input_string);
#endif
