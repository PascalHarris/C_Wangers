//
//  c_wangers_file.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef CFILE_H_
#define CFILE_H_
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <wordexp.h>

#define LOCALPATHLENGTH 1024

#define ALREADY_EXISTS 1
#define CREATE_FAILED -1
#define CREATE_SUCCESS 0

/**
 * expand_path:
 * @path: (type char*) The name of the path to be expanded.
 *
 * Expands the path to its full filesystem path.
 *
 * Returns: char* expanded path
 */
char* expand_path(char* path);

/**
 * make_directory:
 * @path: (type char*) The name of the path to be created.
 * @mode: (type mode_t) The file attributes for the path to be created
 *
 * Creates a directory path.
 *
 * Returns: signed int - ALREADY_EXISTS if path exists, CREATE_FAILED if create failed, CREATE_SUCCESS if successful
 */
signed make_directory(char* path, mode_t mode);

/**
 * file_exists:
 * @filename: (type char*) The name of the file to be verified.
 *
 * Checks to see if a file exists.
 *
 * Returns: bool
 */
bool file_exists (char* filename);

/**
 * line_count:
 * @filename: (type char*) The name of the file to be processed.
 *
 * Provides a count of the number of lines in a file.
 *
 * Returns: int
 */
int line_count(char *filename);
#endif
