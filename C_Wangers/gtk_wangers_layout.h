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
 @brief Creates a fixed-position container with a child widget placed at specified coordinates.
 @discussion Initializes a `GtkFixed` container and places the given widget at `(x, y)` with a fixed size. Useful for pixel-perfect layout scenarios or legacy UI designs where absolute positioning is required.
 @param object A pointer to the widget to be placed inside the container.
 @param x The horizontal position of the widget within the container.
 @param y The vertical position of the widget within the container.
 @param width The requested width of the widget.
 @param height The requested height of the widget.
 @return A `GtkWidget*` representing the container with the positioned child.
 */
GtkWidget* create_container_with_rect (void* object, int x, int y, int width, int height);

/**
 @brief Wraps a widget in a scrollable container.
 @discussion Creates a `GtkScrolledWindow` and adds the given widget as its child. Enables horizontal and vertical expansion to fill available space. Suitable for embedding large or dynamic content in scrollable views.
 @param object A pointer to the widget to be placed inside the scroll view.
 @return A `GtkWidget*` representing the scrollable container.
 */
GtkWidget* create_scrollview_with_object (void* object);
#endif

