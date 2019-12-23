//
//  c_wangers_time.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef CTIME_H_
#define CTIME_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#ifdef WINDOWS_OS
#include "cpw_strptime.h"
#endif

#define EPOCH_DIFF 0x019DB1DED53E8000LL /* 116444736000000000 nsecs */
#define RATE_DIFF 10000000 /* 100 nsecs */
typedef int64_t filetime_t;

/**
 * is_leap_year:
 * @year: (type int) The year to be validated.
 *
 * Checks to see if a year is a leap year
 *
 * Returns: bool
 */
bool is_leap_year(int year);

/**
 * date_is_valid:
 * @day: (type int) The day of the month to be validated.
 * @month: (type int) The month of the year to be validated.
 * @year: (type int) The year to be validated.
 *
 * Validates a date to check that it is valid
 *
 * Returns: bool
 */
bool date_is_valid(int day, int month, int year);

/**
 * timeunixtowindows:
 * @unixtime: (type double time) The time to be validated.
 * @flag: (type char*) time, long, lat.  Should be updated to be an enumeration.
 *
 * Validates a time to check that it is valid
 *
 * Returns: bool
 */
bool time_is_valid(double time, char* flag);

/**
 * timeunixtowindows:
 * @unixtime: (type time_t) The Posix time to be converted.
 *
 * Converts Posix epoch to VMS Time
 *
 * Returns: unsigned long long
 */
unsigned long long timeunixtovms(time_t unixtime);

/**
 * timeunixtowindows:
 * @ftime: (type time_t) The Posix time to be converted.
 *
 * Converts Posix epoch to Windows filetime
 *
 * Returns: filetime_t
 */
filetime_t timeunixtowindows(time_t utime);

/**
 * timewindowstounix:
 * @ftime: (type filetime_t) The Windows time to be converted.
 *
 * Converts Windows filetime to Unix epoch
 *
 * Returns: time_t
 */
time_t timewindowstounix(filetime_t ftime);

/**
 * debug_time:
 * @time: (type tm*) A pointer to a struct of type tm.
 *
 * Outputs all the contents of tm to std_out for debugging purposes.
 *
 * Returns: void
 */
void debug_time(struct tm* time);

/**
 * string_from_time:
 * @input_time: (type time_t) The time to be converted to a string.
 * @format_string: (type char*) The format to be used in the conversion.
 *
 * Creates a human readable string from the provided time using the given format.
 *
 * Returns: char*
 */
char* string_from_time(time_t input_time, char* format_string);

/**
 * time_from_string:
 * @input_string: (type char*) The string to be converted to a time.
 * @format_string: (type char*) The template format that the provided string uses.
 *
 * Converts a human readable string in the given format to a time.
 *
 * Returns: time_t
 */
time_t time_from_string(char* input_string, char* format_string);
#endif
