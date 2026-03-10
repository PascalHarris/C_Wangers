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

#ifndef EPOCH_DIFF
#define EPOCH_DIFF 0x019DB1DED53E8000LL /* 116444736000000000 nsecs */
#endif
#define RATE_DIFF 10000000 /* 100 nsecs */

#define RFC2425 "%Y-%m-%dT%H:%M:%SZ"
#define RFC2445 "%Y%m%dT%H%M%SZ"

typedef int64_t windows_t;

/** Described in https://docs.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.comtypes.filetime?view=netframework-4.8 */
typedef struct {
    uint32_t  dwLowDateTime;
    uint32_t  dwHighDateTime;
} FILETIME;
#define MAX_DATE_FORMAT_LENGTH 40

/**
 @brief Determines whether a given year is a leap year.
 @discussion
 Follows Gregorian calendar rules:
 - Divisible by 4 → potential leap year
 - Divisible by 100 → not a leap year
 - Divisible by 400 → leap year

 @param year The year to evaluate.
 @return true if leap year; false otherwise.
 */
bool is_leap_year(int year);

/**
 @brief Validates a calendar date.
 @discussion
 Checks if the day and month fall within valid ranges.
 Adjusts February length for leap years.

 @param day Day of the month.
 @param month Month (1–12).
 @param year Full year.
 @return true if the date is valid; false otherwise.
 */
bool date_is_valid(int day, int month, int year);

/**
 @brief Validates a time or coordinate value.
 @discussion
 Interprets `time` as `hours.minutes` and validates based on `flag`:
 - `"time"`: 0–23 hours
 - `"long"`: 0–360 degrees
 - `"lat"`: –90 to +90 degrees
 Also ensures fractional part (minutes) ≤ 0.59.

 @param time The time or coordinate value.
 @param flag A string indicating the type ("time", "long", "lat").
 @return true if valid; false otherwise.
 */
bool time_is_valid(double time, char* flag);

/**
 @brief Converts Unix time to VMS time format.
 @discussion
 Multiplies Unix time by 10,000,000 and adds VMS epoch offset.

 @param unixtime Unix timestamp.
 @return VMS time as 64-bit unsigned integer.
 */
unsigned long long timeunixtovms(time_t unixtime);

/**
 @brief Converts Unix time to Windows FILETIME format.
 @discussion
 Applies epoch and rate difference constants.

 @param utime Unix timestamp.
 @return Windows time as `windows_t`.
 */
windows_t timeunixtowindows(time_t utime);

/**
 @brief Converts Windows FILETIME to Unix time.
 @discussion
 Reverses the epoch and rate offset.

 @param ftime Windows time.
 @return Unix timestamp.
 */
time_t timewindowstounix(windows_t ftime);

/**
 @brief Prints detailed breakdown of a `struct tm`.
 @discussion
 Outputs each field of the time structure for debugging.

 @param time Pointer to a `struct tm`.
  */
void debug_time(struct tm* time);

/**
 @brief Formats a time value into a string.
 @discussion
 Uses `strftime` with the given format string.
 Allocates a 128-byte buffer for the result.

 ⚠️ Notes:
 - Caller must free the returned string.
 - Returns empty string if format is null.

 @param input_time Unix timestamp.
 @param format_string Format string for `strftime`.
 @return Formatted time string.
 */
char* string_from_time(time_t input_time, char* format_string);

/**
 @brief Parses a formatted time string into a Unix timestamp.
 @discussion
 Uses `strptime` and `mktime` to convert string to `time_t`.
 Returns 0 if result is out of bounds.

 @param input_string Input time string.
 @param format_string Format string for parsing.
 @return Parsed Unix timestamp or 0 if invalid.
 */
time_t time_from_string(char* input_string, char* format_string);

/**
 @brief Converts Windows FILETIME to Unix time.
 @discussion
 Combines high and low DWORDs, adjusts for epoch and scale.

 ⚠️ Notes:
 - Returns 0 if value exceeds 32-bit `time_t` range.

 @param filetime Pointer to FILETIME structure.
 @return Unix timestamp.
 */
time_t filetime_to_unix(FILETIME *filetime);

/**
 @brief Converts FILETIME to formatted string.
 @discussion
 Converts to Unix time, then formats using `strftime`.
 @param filetime Pointer to FILETIME.
 @param format_string Format string for `strftime`.
 @param result Output buffer.
 @return Number of characters written.
 */
size_t filetime_to_string(FILETIME* filetime, char* format_string, char* result);

/**
 @brief Converts FILETIME to `struct tm`.
 @discussion
 Converts to Unix time and populates the `tm` structure using `gmtime_r`.
 @param filetime Pointer to FILETIME.
 @param result Pointer to `struct tm` to populate.
 */
void filetime_to_tm (FILETIME *filetime, struct tm *result);

/**
 @brief Formats FILETIME into a string.
 @discussion
 Converts to `struct tm` and formats using `strftime`.
 @param ft Pointer to FILETIME.
 @param buflen Size of result buffer.
 @param result Output buffer.
 @param format Format string.
 @return Pointer to result buffer.
 */
char* filetime_to_format(FILETIME* ft, int buflen, char* result, char* format);

/**
 @brief Formats current UTC time into a string.
 @discussion
 Uses `gmtime_r` and `strftime` to format current time.
 @param buflen Size of result buffer.
 @param result Output buffer.
 @param format Format string.
 @return Pointer to result buffer.
 */
char* now_to_format(int buflen, char* result, char* format);

#endif
