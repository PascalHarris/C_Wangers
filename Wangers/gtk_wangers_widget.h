//
//  gtk_wangers_widget.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef WIDGET_H_
#define WIDGET_H_
#include <gtk/gtk.h>

/**
 @brief Creates a GTK button with a label and click callback.
 @discussion Initializes a `GtkButton` with the specified label and connects its "clicked" signal to the provided callback function. The callback receives the given data when triggered. Useful for declarative button creation in UI layouts.
 @param title The label text to display on the button.
 @param callback A pointer to the function to be called when the button is clicked.
 @param data A pointer to user data passed to the callback.
 @return A pointer to the newly created `GtkWidget` representing the button.
 */
GtkWidget* create_button (char* title, void* callback, void* data);
#endif
