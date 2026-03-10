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
 @brief Raises a floating-point number to a given power.
 @discussion Recursively computes x raised to the power y. Returns 1 if y is zero. Uses `pow(x, y - 1)` for non-zero exponents.
 @param x The base value.
 @param y The exponent value.
 @return The result of x raised to the power y.
 */
float RaiseToPower(float x,float y);

/**
 @brief Checks if a string contains only numeric digits.
 @discussion Uses `strspn` to verify that all characters in the input string are digits (0–9).
 @param input_string A null-terminated string to validate.
 @return `true` if the string contains only digits, `false` otherwise.
 */
bool is_a_number(char* input_string);

/**
 @brief Checks if a string represents a valid hexadecimal number.
 @discussion Converts the input to lowercase and verifies that all characters are valid hex digits or formatting symbols. Accepts optional `x`, parentheses, and spaces.
 @param input_string A null-terminated string to validate.
 @return `true` if the string is a valid hex representation, `false` otherwise.
 */
bool is_a_hex_number(char* input_string);

/**
 @brief Calculates the number of bytes needed to represent a number.
 @discussion Shifts the input number right by 8 bits until it becomes zero, counting the number of shifts.
 @param input_number A signed 64-bit integer.
 @return The number of bytes required to store the input value.
 */
int bytesNeeded(long long input_number);

/**
 @brief Converts a string to a boolean value.
 @discussion Compares the lowercase version of the input string against a list of truthy values: "yes", "true", "1", "on".
 @param input_string A null-terminated string to interpret.
 @return `true` if the string matches a known truthy value, `false` otherwise.
 */
bool bool_from_string(char* input_string);

#endif
