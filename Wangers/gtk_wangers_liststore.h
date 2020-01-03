//
//  gtk_wangers_liststore.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef LISTSTORE_H_
#define LISTSTORE_H_
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * traverse_list_store:
 * @liststore: (type GtkListStore) a pointer to the treeview which will be saved.
 *
 * @liststore must not be %NULL.
 *
 * Iterates through the entire treeview.  Not fully implemented yet.
 *
 * Returns: void
 */
void traverse_list_store (GtkListStore *liststore);


#endif
