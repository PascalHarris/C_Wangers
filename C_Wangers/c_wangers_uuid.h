//
//  c_wangers_uuid.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef CUUID_H_
#define CUUID_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/**
 @brief Generates a pseudo-random UUID string.
 @discussion
 Constructs a UUID-like string using `rand()` and formats it as:
   `%x%x-%x-%x-%x-%x%x%x`
 This mimics the structure of a version 4 UUID, including:
 - Randomized segments
 - Version bits (`0x4000`)
 - Variant bits (`0x8000` to `0xBFFF`)

 If `length` is between 1 and 56, returns a truncated version of the UUID.
 Otherwise, returns the full 56-character string.

 ⚠️ Notes:
 - Uses `srand(time(NULL))` for seeding, which may produce duplicate values if called rapidly
 - Caller is responsible for freeing the returned buffer
 - Not cryptographically secure

 @param length Desired length of the UUID string (0 or >56 returns full UUID).
 @return A heap-allocated string containing the UUID or its truncated form.
 */
char* uuid_generator(int length);

/**
 @brief Generates a random alphanumeric key of specified length.
 @discussion
 Selects characters from a static pool of digits, uppercase, and lowercase letters.
 Uses `rand()` to randomly index into the pool.

 ⚠️ Notes:
 - Caller is responsible for freeing the returned buffer
 - Not cryptographically secure
 - Does not seed `rand()` internally; caller should seed if needed

 @param length The desired length of the key.
 @return A heap-allocated string containing the random key.
 */
char* generate_key(const int length);

#endif
