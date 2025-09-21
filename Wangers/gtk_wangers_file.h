//
//  gtk_wangers_file.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef FILE_H_
#define FILE_H_
#include "gtk_wangers.h"

#define EMPTY_DOCUMENT "Untitled"

/**
 @brief Displays a GTK file chooser dialogue for saving a document.
 @discussion Opens a modal save dialogue attached to the parent window. If the document has no filename (`EMPTY_DOCUMENT`), sets a default name. Otherwise, preselects the existing filename. On confirmation, updates the document's filename, sets the window title, and invokes the save action callback.
 @param parent_window A pointer to the `GtkWindow` that owns the dialogue.
 @param dialogue_parameters A pointer to a `struct document` containing the window, filename, file data, and save action pointer.
 */
void show_save_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters);

/**
 @brief Displays a GTK file chooser dialogue for opening a document.
 @discussion Opens a modal open dialogue attached to the parent window. On confirmation, updates the document's filename, sets the window title, and invokes the open action callback.
 @param parent_window A pointer to the `GtkWindow` that owns the dialogue.
 @param dialogue_parameters A pointer to a `struct document` containing the window, filename, file data, and open action pointer.
 */
void show_open_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters);
#endif
