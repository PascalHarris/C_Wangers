//
// Created by Pascal Harris LC on 19/12/2019.
//

#include "gtk_wangers_liststore.h"

void traverse_list_store (GtkListStore *liststore) {
    GtkTreeIter  iter;
    gboolean     valid;

    g_return_if_fail ( liststore != NULL );

    /* Get first row in list store */
    valid = gtk_tree_model_get_iter_first(GTK_TREE_MODEL(liststore), &iter);

    while (valid) {
        /* ... do something with that row using the iter ...          */
        /* (Here column 0 of the list store is of type G_TYPE_STRING) */
        //gtk_list_store_set(liststore, &iter, 0, "Joe", -1);

        /* Make iter point to the next row in the list store */
        valid = gtk_tree_model_iter_next(GTK_TREE_MODEL(liststore), &iter);
    }
}
