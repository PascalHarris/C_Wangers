//
//  gtk_wangers_combobox.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef COMBOBOX_H_
#define COMBOBOX_H_
#include <gtk/gtk.h>

/**
 @brief Creates a GtkListStore containing a variable number of string entries.
 @discussion Initializes a single-column list store of type `G_TYPE_STRING` and populates it with the provided string arguments. Useful for populating combo boxes or list views with static string options.
 @param num_args The number of string arguments to insert.
 @param ... A variable list of `gchar*` strings to populate the list store.
 @return A pointer to the newly created `GtkListStore` containing the provided strings.
 */
GtkListStore* liststore_with_string(int num_args, ...);

/**
 @brief Creates a combo box cell renderer backed by a string list model.
 @discussion Initializes a `GtkCellRendererCombo` with editable entry and dropdown behavior. The provided list model is used as the source of selectable items.
 @param listmodel A `GtkListStore` containing string entries for the combo box.
 @return A pointer to a configured `GtkCellRenderer` suitable for use in tree views or combo box columns.
 */
GtkCellRenderer* new_combobox_cell(GtkListStore* listmodel);
#endif
