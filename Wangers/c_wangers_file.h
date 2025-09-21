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
 @brief Expands a shell-style path to its absolute form.
 @discussion Uses `wordexp` to resolve shell variables and tilde notation in the input path. The result is copied into a static buffer and returned. If the expanded path exceeds `LOCALPATHLENGTH`, the result is truncated.
 @param path A shell-style path string (e.g., "~/Documents").
 @return A pointer to a static buffer containing the expanded path.
 */
char* expand_path(char* path);

/**
 @brief Creates a directory at the specified path with the given mode.
 @discussion Attempts to create a directory using `mkdir`. If the directory already exists, returns `ALREADY_EXISTS`. On other errors, prints a message and returns `CREATE_FAILED`. On success, returns `CREATE_SUCCESS`.
 @param path The directory path to create.
 @param mode The permission mode (e.g., `0755`) for the new directory.
 @return A status code: `CREATE_SUCCESS`, `ALREADY_EXISTS`, or `CREATE_FAILED`.
 */
signed make_directory(char* path, mode_t mode);

/**
 @brief Checks whether a file exists at the given path.
 @discussion Uses `stat` to determine if the file or directory exists. Returns true if the file is found, false otherwise.
 @param filename The path to the file or directory.
 @return `true` if the file exists, `false` otherwise.
 */
bool file_exists (char* filename);

/**
 @brief Counts the number of lines in a text file.
 @discussion Opens the file and reads character-by-character, incrementing a counter for each newline. Adds one final line if the file is non-empty. Returns zero if the file cannot be opened.
 @param filename The path to the text file.
 @return The number of lines in the file, or zero if the file could not be opened.
 */
int line_count(char *filename);
#endif
