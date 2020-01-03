//
//  gtk_wangers_tableview.c
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#include "gtk_wangers_tableview.h"

void save_table_to_text_file(GtkWidget *treeview, gchar* filename, int number_of_columns) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GString *str = g_string_new ("");
    GtkTreeIter iter;
    gboolean valid;
    
    for (valid = gtk_tree_model_get_iter_first (model, &iter); valid; valid = gtk_tree_model_iter_next (model, &iter)) {
        for (int i = 0; i < number_of_columns; i++) {
            char *string = NULL;
            gtk_tree_model_get (model, &iter, i, &string, -1);
            if (string != NULL) {
                g_string_append_printf (str, "%s,", string);
                g_free (string);
            }
        }
        g_string_append_printf (str, "\n");
    }
    g_file_set_contents (filename, str->str, -1, NULL);
    
    g_string_free (str, TRUE);
}

void on_treeview_row_activated (GtkTreeView *view, GtkTreePath *path, GtkTreeViewColumn *col, gpointer userdata) {
    GtkTreeIter   iter;
    GtkTreeModel *model;
    
    model = gtk_tree_view_get_model(view);
    
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gchar *name;
        
        //    gtk_tree_model_get(model, &iter, COL_NAME, &name, -1);
        gtk_tree_model_get(model, &iter, 0, &name, -1); // 0 is the first column.  We can iterate through of course as is done later.
        
        g_print ("The row containing the name '%s' has been double-clicked.\n", name);
        
        g_free(name);
    }
}

void insert_list_row (GtkWidget *widget, GtkWidget *treeview) {
    int i = get_selected_row_index(treeview, false);
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    gtk_list_store_insert_with_values(GTK_LIST_STORE(model), NULL, i, EMPTY_ROW);
}

void insert_tree_row (GtkWidget *widget, GtkWidget *treeview) {
    int i = get_selected_row_index(treeview, true);
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter = get_selected_tree_node(treeview);
    if (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
        bool has_parent;
        GtkTreeIter parent_iter = get_parent_iter(model, iter, &has_parent);
        if (has_parent && gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &parent_iter)) {
            gtk_tree_store_insert_with_values(GTK_TREE_STORE(model), NULL, &parent_iter, -1, EMPTY_ROW);
        } else {
            gtk_tree_store_insert_with_values(GTK_TREE_STORE(model), &iter, NULL, i, EMPTY_ROW);
        }
        g_print("e\n");
    }
}

void create_child_for_parent (GtkWidget *widget, GtkWidget *treeview) {
    int i = get_selected_row_index(treeview, true);
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter = get_selected_tree_node(treeview);
    if (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
        gtk_tree_store_insert_with_values(GTK_TREE_STORE(model), NULL, &iter, i, EMPTY_ROW);
    }
}

void add_list_row (GtkWidget *widget, GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    gtk_list_store_insert_with_values(GTK_LIST_STORE(model), NULL, -1, EMPTY_ROW);
}

void add_tree_row (GtkWidget *widget, GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    //gtk_list_store_insert_with_values(GTK_LIST_STORE(model), NULL, -1, EMPTY_ROW);
    gtk_tree_store_insert_with_values(GTK_TREE_STORE(model), NULL, NULL, -1, EMPTY_ROW);
}

void list_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data) {
    GtkTreeModel *model = (GtkTreeModel *)data;
    GtkTreePath *path = gtk_tree_path_new_from_string (path_string);
    GtkTreeIter iter;
    gint column = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (cell), "column_number"));
    gtk_tree_model_get_iter (model, &iter, path);
    gtk_list_store_set (GTK_LIST_STORE (model), &iter, column, new_text, -1);
    gtk_tree_path_free (path);
}

void tree_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data) {
    GtkTreeModel *model = (GtkTreeModel *)data;

    GtkTreePath *path = gtk_tree_path_new_from_string (path_string);
    GtkTreeIter iter;
    gint column = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (cell), "column_number"));
    gtk_tree_model_get_iter (model, &iter, path);

    int new_string_size = strlen(new_text) < 20?20:strlen(new_text)*2;
    char *upd_text=(char *)calloc( new_string_size, sizeof(char) ); // need to malloc twice the size of the text to allow modification - need a better solution later
    strcpy(upd_text, new_text);

    if ( validator_ptr == NULL || ( ( validator_ptr != NULL ) && ( (*validator_ptr)(cell, path_string, (char **) &upd_text, model) ) ) )  {
        gtk_tree_store_set(GTK_TREE_STORE (model), &iter, column, upd_text, -1);
    }

    free(upd_text);
    gtk_tree_path_free (path);
}

void editing_started (GtkCellRenderer *cell, GtkCellEditable *editable, const gchar *path, gpointer data) {
    
}

GtkTreeIter get_parent_iter(GtkTreeModel* model, GtkTreeIter child_iter, bool* has_parent) {
    GtkTreeIter iter;
    GtkTreePath *path = gtk_tree_model_get_path (model, &child_iter);
    *has_parent = gtk_tree_path_up (path);
    if (*has_parent) {
        gtk_tree_model_get_iter(model, &iter, path);
    }
    return iter;
}

GtkTreeIter get_selected_tree_node(GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter;
    gtk_tree_selection_get_selected(selection, &model, &iter);
    return iter;
}

int get_selected_row_index(GtkWidget *treeview, bool istree) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter = get_selected_tree_node(treeview);
    bool valid = istree?gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter):gtk_list_store_iter_is_valid(GTK_LIST_STORE(model), &iter);
    if (valid) {
//    if (gtk_list_store_iter_is_valid(GTK_LIST_STORE(model), &iter)) {
        GtkTreePath *path = gtk_tree_model_get_path (model, &iter);
        int *i = gtk_tree_path_get_indices(path);
        return *i;
    }
    return -1;
}

void delete_list_row (GtkWidget *widget, GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter = get_selected_tree_node(treeview);
    if (gtk_list_store_iter_is_valid(GTK_LIST_STORE(model), &iter)) {
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
    }
}

void delete_tree_row (GtkWidget *widget, GtkWidget *treeview) {
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
    GtkTreeIter iter = get_selected_tree_node(treeview);
    if (gtk_tree_store_iter_is_valid(GTK_TREE_STORE(model), &iter)) {
        gtk_tree_store_remove(GTK_TREE_STORE(model), &iter);
    }
}

gboolean cell_selection_function (GtkTreeSelection *selection,
                              GtkTreeModel *model,
                              GtkTreePath *path,
                              gboolean path_currently_selected,
                              gpointer userdata) {
    /*    GtkTreeIter iter;
     
     if (gtk_tree_model_get_iter(model, &iter, path)) {
     gchar *name;
     
     gtk_tree_model_get(model, &iter, FILE_NAME, &name, -1);
     
     if (!path_currently_selected) {
     g_print ("%s is going to be selected.\n", name);
     } else {
     g_print ("%s is going to be unselected.\n", name);
     }
     
     g_free(name);
     }
     */
    return TRUE; /* allow selection state to change */
}

GtkWidget* create_tableview_with_model (void* model) {
    GtkWidget* tableview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));
    GtkTreeSelection* selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tableview));
    gtk_tree_selection_set_select_function(selection, cell_selection_function, NULL, NULL);
    g_object_unref(model);
    return tableview;
}

void add_column_to_table (bool editable, bool tree_store, struct model_definition model_def, const gchar *title, GtkCellRenderer *cell, guint column_num, ...) {
    va_list args;
    GtkTreeViewColumn *column = gtk_tree_view_column_new ();
    GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(model_def.tableview));

    g_object_set (cell, "editable", editable, NULL);
    g_object_set_data (G_OBJECT (cell), "column_number", GINT_TO_POINTER (column_num));

    validator_ptr = model_def.validator_ptr;

    gtk_tree_view_column_set_title (column, title);
    gtk_tree_view_column_pack_start (column, cell, TRUE);
    g_signal_connect (cell, "edited", tree_store?G_CALLBACK (tree_cell_edited):G_CALLBACK (list_cell_edited), model);

    g_signal_connect (cell, "editing-started", G_CALLBACK (editing_started), NULL);

    va_start (args, column_num);
    gchar *attribute = va_arg (args, gchar *);
    gint gcolumn;
    while (attribute != NULL) {
        gcolumn = va_arg (args, gint);
        gtk_tree_view_column_add_attribute(column, cell, attribute, gcolumn);
        attribute = va_arg (args, gchar *);
    }
    va_end (args);

    gtk_tree_view_append_column(GTK_TREE_VIEW(model_def.tableview), column);
}

void add_columns_to_table (bool editable, bool tree_store, struct model_definition model_def, ...) {
    va_list args;

    va_start (args, model_def);
    gchar *title = va_arg (args, gchar *);
    gint gcolumn;
    while (title != NULL) {
        gcolumn = va_arg (args, gint);
        add_column_to_table(true, true, model_def, title, gtk_cell_renderer_text_new(), gcolumn, "text", gcolumn, NULL);
        title = va_arg (args, gchar *);
    }
    va_end (args);
}

model_definition set_table_with_validator(void(*validator_ptr), gpointer tableview) {
    model_definition model_def;
    model_def.validator_ptr = validator_ptr;
    model_def.tableview = tableview;
    return model_def;
}
