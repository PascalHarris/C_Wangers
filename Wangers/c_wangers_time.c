#include "c_wangers_time.h"

bool is_leap_year(int year) {
    bool result;
    if ( (year%4) != 0 ) {
        result = false;
    } else if ( (year%400) == 0 ) {
        result = true;
    } else if ( (year%100) == 0 ) {
        result = false;
    } else {
        result = true;
    }
    return ( result );
}

bool date_is_valid(int day, int month, int year) {
    bool valid = true;
    int month_length[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( is_leap_year(year) ) {
        month_length[2] = 29;
    }

    if ( month < 1 || month > 12 ) {
        valid = false;
    } else if ( day < 1 || day > month_length[month] ) {
        valid = false;
    }

    return ( valid );
}

bool time_is_valid(double time, char* flag) {
    bool valid = true;
    double minutes, hours;

    minutes = modf((double)time,&hours);

    if ((strncmp(flag, "time", (size_t)strlen(flag)) == 0) && ((hours < 0) || (hours > 23))) {
        valid = false;
    } else if ((strncmp(flag, "long", (size_t)strlen(flag)) == 0) && ((hours < 0) || (hours > 360))) {
        valid = false;
    } else if ((strncmp(flag, "lat", (size_t)strlen(flag)) == 0) && ((hours < -90) || (hours > 90))) {
        valid = false;
    }

    if ( minutes > 0.59 ) {
        valid = false;
    }

    return ( valid );
}

unsigned long long timeunixtovms(time_t unixtime) {
    unsigned long long timevalue = unixtime;
    timevalue *= 10000000;
    timevalue += 0x07C95674BEB4000ULL;
    return timevalue;
}

filetime_t timeunixtowindows(time_t utime) {
    int64_t tconv = ((int64_t)utime * RATE_DIFF) + EPOCH_DIFF;
    return tconv;
}

time_t timewindowstounix(filetime_t ftime) {
    int64_t tconv = (ftime - EPOCH_DIFF) / RATE_DIFF;
    return (time_t)tconv;
}

void debug_time(struct tm* time) {
    printf("%d   seconds after the minute (0-61)\n", (*time).tm_sec);
    printf("%d   minutes after the hour (0-59)\n", (*time).tm_min);
    printf("%d   hours since midnight (0-23)\n", (*time).tm_hour);
    printf("%d   day of the month (1-31)\n", (*time).tm_mday);
    printf("%d   months since january (0-11)\n", (*time).tm_mon);
    printf("%d   years since 1900\n", (*time).tm_year);
    printf("%d   days since sunday (0-6)\n", (*time).tm_wday);
    printf("%d   days since Jan 1 (0-365)\n", (*time).tm_yday);
    printf("%d   DST Flag (0 / 1)\n", (*time).tm_isdst);
}

char* string_from_time(time_t input_time, char* format_string) {
    if (format_string == NULL) {
        return "";
    }
    struct tm* times = {0};
    times = localtime(&input_time);

    int return_string_size = 128; // 128 bytes should be ample for our time in any format!
    char* return_string = (char*)calloc(return_string_size, sizeof(char));
    strftime(return_string, return_string_size, format_string, times);

    return return_string;
}

time_t time_from_string(char* input_string, char* format_string) {
    if (format_string == NULL) {
        return 0;
    }
    struct tm times = {0};
    time_t t;
    strptime(input_string, format_string, &times);
    t = mktime(&times);
    return t<1||t>5000000000?0:t;
}

