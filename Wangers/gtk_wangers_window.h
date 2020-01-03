//
//  gtk_wangers_window.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//
#ifndef WINDOW_H_
#define WINDOW_H_
#include <gtk/gtk.h>
#include <stdbool.h>

// May want to include callback to procedures that should be run when closing the window?  Document save, for example.

/**
 * Structure containing a definition for the about box.
 * This structure will be renamed at some point to be more generic.
 */
typedef struct about_box_definition {
    char* title;         /**< @title:  (type char*) The title for the about box.  */
    char* about_message; /**< @about_message:  (type char*) The message to be displayed.  */
    GtkWindow *window;   /**< @window:  (type GtkWindow*) The window that the about box will be modal for.  */
} about_box_definition;

/**
 * destroy:
 * @widget: (type GtkWidget*) The window that will be closed. Not used.
 * @data: (nullable) (type gpointer) Not used.
 *
 * Destroys the application. Use only if the application should quit when the window is closed
 *
 * Returns: void
 */
void destroy (GtkWidget *widget, gpointer data);

/**
 * create_window:
 * @width: (type int) The initial width for the window.
 * @height: (type int) The initial height for the window.
 * @title: (type char*) The title to be used for the window.
 * @will_destroy: (type bool) Whether or not the application should quit when the window is closed.
 *
 * Creates a new window of the specified width and height
 *
 * Returns: GtkWidget
 */
GtkWidget* create_window (int width, int height, char* title, bool will_destroy);

/**
 * show_dialogue:
 * @button: (type GtkButton) The button pressed to show the dialogue.  Not used.
 * @user_data: (type void*) Pointer to struct of type about_box_definition which will define the contents of the dialogue.
 *
 * Displays a dialogue showing the contents of the provided struct.
 *
 * Returns: void
 */
void show_dialogue (GtkButton *button, gpointer user_data);

/**
 * about_box_definition:
 * @title: (type char*) The title for the about box.
 * @about_message: (type char*) The message to be displayed.
 * @window: (type GtkWindow*) The window that the about box will be modal for.
 *
 * Sets up the about box contents.
 * This will be renamed at some point to be more generic - it's not just for building about boxes!
 *
 * Returns: void
 */
about_box_definition define_about_box(char* title, char* about_message, GtkWindow* window);
#endif
