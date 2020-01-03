//
//  cpw_strptime.cpp
//
//  Created by Pascal Harris on 11/12/2019.
//  Copyright (c) 2019 Pascal Harris, 45RPM Software. All rights reserved.
//

#include <time.h>
#include <iomanip>
#include <sstream>
#include "cpw_strptime.h"

#ifdef WINDOWS_OS

extern "C" char* strptime(const char *buf, const char *fmt, struct tm *tm) {
    std::istringstream input(buf);
    input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
    input >> std::get_time(tm, fmt);
    if (input.fail()) {
        return nullptr;
    }
    return (char*)(buf + input.tellg());
}

#endif