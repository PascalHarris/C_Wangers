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
 * liststore_with_string:
 * @num_args: (type int) the number of items in the list store.
 * @arg_list: (nullable) (type gchar*) a list of arguments, all of type gchar*.
 *
 * @num_args must not be %NULL.
 * @arg_list must contain 1 or more arguments.
 *
 * Sets up the liststore for the combo box.
 *
 * Returns: GtkListStore
 */
GtkListStore* liststore_with_string(int num_args, ...);

/**
 * new_combobox_cell:
 * @listmodel: (type GtkListStore) the list model for the combo-box.
 *
 * @listmodel must not be %NULL.
 *
 * Sets up a combobox cell containing the items in the supplied GtkListModel.
 *
 * Returns: GtkCellRenderer
 */
GtkCellRenderer* new_combobox_cell(GtkListStore* listmodel);
#endif
