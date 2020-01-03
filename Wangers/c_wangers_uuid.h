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
 * uuid_generator:
 * @length: (type int) The length of the UUID to be generated
 *
 * Generates a UUID of the required length.
 * Lengths with a value of 0 or values greater than 56 result in full length UUID
 *
 * Returns: char*
 */
char* uuid_generator(int length);

/**
 * generate_key:
 * @length: (type int) The length of the key to be generated
 *
 * Generates a key of the required length.
 *
 * Returns: char*
 */
char* generate_key(const int length);

#endif
