//
//  cpw_strptime.h
//
//  Created by Pascal Harris on 11/12/2019.
//  Copyright (c) 2019 Pascal Harris, 45RPM Software. All rights reserved.
//

//#define WINDOWS_OS // Uncomment if building on Windows only.

#ifdef WINDOWS_OS

#ifndef STRPTIME_H
#define STRPTIME_H

#define ALT_E          0x01
#define ALT_O          0x02
#define LEGAL_ALT(x)   { ; }
#define TM_YEAR_BASE   (1900)

#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 @brief Parses a date/time string into a `struct tm` using C++ streams.
 @discussion
 This function mimics the behavior of the POSIX `strptime`, using `std::istringstream` and `std::get_time`:
 - Applies the current locale via `setlocale(LC_ALL, nullptr)`
 - Parses the input string `buf` using the format string `fmt`
 - Populates the `tm` structure with parsed values
 - Returns a pointer to the next unread character in `buf`, or `nullptr` on failure

 ⚠️ Notes:
 - Locale-sensitive: parsing depends on the current C locale
 - `tellg()` returns the stream position after parsing, used to compute the return pointer
 - Marked `extern "C"` for C linkage compatibility

 @param buf The input string containing the date/time.
 @param fmt The format string (e.g. `"%Y-%m-%d %H:%M:%S"`).
 @param tm A pointer to a `struct tm` to be filled with parsed values.
 @return A pointer to the next character in `buf` after the parsed portion, or `nullptr` if parsing fails.
 */
char * strptime(const char *buf, const char *fmt, struct tm *tm);

#ifdef __cplusplus
}
#endif

static const char *day[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday"
};

static const char *abday[7] = {
        "Sun","Mon","Tue","Wed","Thu","Fri","Sat"
};

static const char *mon[12] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
};

static const char *abmon[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char *am_pm[2] = {
        "AM", "PM"
};

#endif

#endif
