//
//  gtk_wangers_document.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef DOCUMENT_H_
#define DOCUMENT_H_
#include "gtk_wangers.h"

/**
 * Structure containing the document definition
 */
typedef struct document {
    GtkWindow *parent_window;  /**< @parent_window:  (type GtkWindow*) The window that the document is contained in.  */
    void (*save_action_ptr)(); /**< @save_action_ptr: (type void*) Pointer to the function that should be executed when saving the file.  */
    void (*open_action_ptr)(); /**< @open_action_ptr: (type void*) Pointer to the function that should be executed when opening the file.  */
    gchar* filename;           /**< @filename:  (type gchar*) The filename of the document.  */
    void* filedata;            /**< @filedata:  (type void*) The data content of the document.  */
} document;

/**
 * build_document_with_characteristics:
 * @parent_window: (type GtkWindow*) The window that the document is contained in.
 * @save_action_ptr: (type void*) function pointer to the function that should be executed when saving the file.
 * @open_action_ptr: (type void*) function pointer to the function that should be executed when opening the file.
 * @filename: (type gchar*) the filename for the document.
 * @filedata: (type void*) the file data content of the document.
 *
 * @parent_window must not be %NULL.
 * @save_action_ptr must not be %NULL.
 * @open_action_ptr must not be %NULL.
 * @filename must not be %NULL.
 * @filedata must not be %NULL.
 *
 * Sets up the struct containing the document data, filename, window and related functions.
 *
 * Returns: struct document
 */
document build_document_with_characteristics(GtkWindow *parent_window,
                                             void (*save_action_ptr),
                                             void (*open_action_ptr),
                                             gpointer filename,
                                             gpointer filedata);

#endif
