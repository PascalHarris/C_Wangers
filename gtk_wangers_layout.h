//
//  gtk_wangers_layout.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef LAYOUT_H_
#define LAYOUT_H_
#include <gtk/gtk.h>

// May want to define a rect struct containing the size / position parameters

/**
 * create_container_with_rect:
 * @object: (type void*) The object to be put inside a view.
 * @x: (type int) The x location of the object.
 * @y: (type int) The y location of the object.
 * @width: (type int) The width of the object.
 * @height: (type int) The height of the object.
 *
 * @object must not be %NULL.
 * @x must not be %NULL.
 * @y must not be %NULL.
 * @width must not be %NULL.
 * @height must not be %NULL.
 *
 * Creates a new view using the supplied object at the supplied size.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_container_with_rect (void* object, int x, int y, int width, int height);

/**
 * create_scrollview_with_object:
 * @object: (type void*) The object to be put inside a scroll view.
 *
 * @object must not be %NULL.
 *
 * Creates a new scrollview using the supplied object.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_scrollview_with_object (void* object);
#endif

