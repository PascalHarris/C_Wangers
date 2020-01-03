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
 * show_save_dialogue:
 * @parent_window: (type GtkWindow*) The window that the document is contained in.
 * @dialogue_parameters: (type void*) a pointer to a struct of type document containing the document definition.
 *
 * @parent_window must not be %NULL.
 * @dialogue_parameters must not be %NULL.
 *
 * Shows the save dialogue.
 *
 * @see build_document_with_characteristics in gtk_wangers_document
 *
 * Returns: void
 */
void show_save_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters);

/**
 * show_open_dialogue:
 * @parent_window: (type GtkWindow*) The window that the document is contained in.
 * @dialogue_parameters: (type void*) a pointer to a struct of type document containing the document definition.
 *
 * @parent_window must not be %NULL.
 * @dialogue_parameters must not be %NULL.
 *
 * Shows the open dialogue.
 *
 * @see build_document_with_characteristics in gtk_wangers_document
 *
 * Returns: void
 */
void show_open_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters);
#endif
