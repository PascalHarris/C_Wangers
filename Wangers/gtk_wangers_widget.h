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
 * create_button:
 * @title: (type char*) a label for the button.
 * @callback: (type void*) function pointer to the action for the button.
 * @data: (nullable) (type void*) parameters for the callback.
 *
 * @title must not be %NULL.
 * @callback must not be %NULL.
 *
 * Creates a button widget.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_button (char* title, void* callback, void* data);
#endif
