#include "gtk_wangers_combobox.h"

GtkListStore* liststore_with_string(int num_args, ...) {
    va_list args;
    GtkListStore* listmodel = gtk_list_store_new (1, G_TYPE_STRING);
    GtkTreeIter iter;
    va_start (args, num_args);
    for (int i = 0; i < num_args; i++) {
        gtk_list_store_append (listmodel, &iter);
        gtk_list_store_set (listmodel, &iter, 0, va_arg (args, gchar *), -1);
    }
    va_end (args);
    
    return listmodel;
}

GtkCellRenderer* new_combobox_cell(GtkListStore* listmodel) {
    GtkCellRenderer* renderer = gtk_cell_renderer_combo_new ();
    g_object_set (renderer, "text-column", 0, "editable", TRUE, "has-entry", TRUE, "model", listmodel, NULL);
    return renderer;
}

