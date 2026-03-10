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
 @brief Constructs a `document` structure with associated window and action pointers.
 @discussion Initializes a `document` instance with its parent window, save/open function pointers, and associated filename and file data. This is useful for encapsulating document-related state and behavior in GTK applications.
 @param parent_window A pointer to the `GtkWindow` that owns or displays the document.
 @param save_action_ptr A function pointer for the document's save action.
 @param open_action_ptr A function pointer for the document's open action.
 @param filename A `gpointer` representing the document's filename (typically a `gchar*`).
 @param filedata A `gpointer` representing the document's content or metadata.
 @return A fully initialized `document` structure.
 */
document build_document_with_characteristics(GtkWindow *parent_window,
                                             void (*save_action_ptr),
                                             void (*open_action_ptr),
                                             gpointer filename,
                                             gpointer filedata);

#endif
