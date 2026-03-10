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
 @brief Iterates through all rows in a `GtkListStore`.
 @discussion Traverses the list store from the first row to the end using a `GtkTreeIter`. Intended for performing operations on each row, such as reading or modifying cell values. Assumes column 0 is of type `G_TYPE_STRING`. No action is performed unless the commented line is activated.
 @param liststore A pointer to the `GtkListStore` to be traversed.
 */
void traverse_list_store (GtkListStore *liststore);


#endif
