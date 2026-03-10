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
 @brief Terminates the GTK main loop.
 @discussion Connected to the "destroy" signal of a top-level window. When triggered, it exits the GTK application.
 @param widget The widget that emitted the signal.
 @param data Optional user data (unused).
 */
void destroy (GtkWidget *widget, gpointer data);

/**
 @brief Creates a top-level GTK window with optional destroy behavior.
 @discussion Initializes a `GtkWindow` with the specified dimensions and title. If `will_destroy` is true, connects the "destroy" signal to terminate the GTK main loop.
 @param width The default width of the window.
 @param height The default height of the window.
 @param title The title to display in the window's title bar.
 @param will_destroy Whether to connect the window's "destroy" signal to `gtk_main_quit`.
 @return A pointer to the newly created `GtkWidget` representing the window.
 */
GtkWidget* create_window (int width, int height, char* title, bool will_destroy);

/**
 @brief Displays a modal "About" dialogue with a message.
 @discussion Creates a `GtkDialog` with a title and message from an `about_box_definition` struct. Adds a centered label and an "Okay" button. Destroys the dialogue on response.
 @param button The button that triggered the dialogue (unused).
 @param user_data A pointer to an `about_box_definition` containing title, message, and parent window.
 */
void show_dialogue (GtkButton *button, gpointer user_data);

/**
 @brief Constructs an `about_box_definition` for use in modal dialogues.
 @discussion Initializes a struct with title, message, and parent window for use in `show_dialogue`.
 @param title The title of the dialogue window.
 @param about_message The message to display in the dialogue.
 @param window A pointer to the parent `GtkWindow`.
 @return A fully initialized `about_box_definition` struct.
 */
about_box_definition define_about_box(char* title, char* about_message, GtkWindow* window);
#endif
