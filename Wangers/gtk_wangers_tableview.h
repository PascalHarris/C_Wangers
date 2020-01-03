//
//  gtk_wangers_tableview.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef TABLEVIEW_H_
#define TABLEVIEW_H_
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdlib.h>
#define EMPTY_ROW -1

/**
 * Structure containing the table and its validator, if relevant
 */
typedef struct model_definition {
    bool (*validator_ptr)(); /**< @validator_ptr: (type void*) Pointer to the validator code, if required. May be NULL. Return bool */
    GtkWidget *tableview;    /**< @tableview: (type GtkWidget*) Pointer to the table which will be populated */
} model_definition;

bool (*validator_ptr)(GtkCellRendererText *, const gchar *, char**, gpointer);

/**
 * save_table_to_text_file:
 * @treeview: (type GtkWidget*) a pointer to the treeview which will be saved.
 * @filename: (type gchar*) the name of the file which will be created.
 * @number_of_columns: (type int) the number of columns that the table has.
 *
 * @treeview must not be %NULL.
 * @filename must not be %NULL.
 *
 * Dumps the contents of a treeview table to disk.
 *
 * Returns: void
 */
void save_table_to_text_file(GtkWidget *treeview, gchar* filename, int number_of_columns);

/**
 * on_treeview_row_activated:
 * @view: (type GtkTreeView) a pointer to the treeview which will be saved.
 * @path: (type GtkTreePath) a pointer to the path of the activated row.
 * @col: (nullable) (type GtkTreeViewColumn) a pointer to the column that the activated cell is in.
 * @userdata: (nullable) (type gpointer) a pointer to userdata. Not used at present.
 *
 * @view must not be %NULL.
 * @path must not be %NULL.
 *
 * Performs an action when a cell is activated (clicked on).  Not fully implemented yet.
 *
 * Returns: void
 */
void on_treeview_row_activated (GtkTreeView *view, GtkTreePath *path, GtkTreeViewColumn *col, gpointer userdata);

/**
 * insert_list_row:
 * @widget: (nullable) (type GtkWidget) a pointer to the new list row that will be inserted.
 * @treeview: (type GtkWidget) a pointer to the list view which will be modified.
 *
 * @treeview must not be %NULL.
 *
 * Inserts a new row into the list before the row that the currently selected row is in.
 *
 * Returns: void
 */
void insert_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * insert_tree_row:
 * @widget: (nullable) (type GtkWidget) a pointer to the new tree row that will be inserted.
 * @treeview: (type GtkWidget) a pointer to the treeview which will be modified.
 *
 * @treeview must not be %NULL.
 *
 * Inserts a new row into the tree before the row that the currently selected row is in.
 *
 * Returns: void
 */
void insert_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * create_child_for_parent:
 * @widget: (nullable) (type GtkWidget) a pointer to the new tree row that will be created.
 * @treeview: (type GtkWidget) a pointer to the treeview which will be modified.
 *
 * @treeview must not be %NULL.
 *
 * Creates a child row for the currently selected parent into the tree.
 *
 * Returns: void
 */
void create_child_for_parent (GtkWidget *widget, GtkWidget *treeview);

/**
 * add_list_row:
 * @widget: (nullable) (type GtkWidget) a pointer to the new list row that will be added.
 * @treeview: (type GtkWidget) a pointer to the treeview which will be modified.
 *
 * @treeview must not be %NULL.
 *
 * Adds a new row into the list add the end of the treeview.
 *
 * Returns: void
 */
void add_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * add_tree_row:
 * @widget: (nullable) (type GtkWidget) a pointer to the new tree row that will be added.
 * @treeview: (type GtkWidget) a pointer to the treeview which will be modified.
 *
 * @treeview must not be %NULL.
 *
 * Adds a new row into the list add the end of the treeview.
 *
 * Returns: void
 */
void add_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * list_cell_edited:
 * @cell: (type GtkCellRendererText) the cell that has been updated - from this we can get the column number.
 * @path_string: (type const gchar) the path to the row in the tableview that will need to be updated.
 * @new_text: (type const gchar) the new text that the cell will be populated with.
 * @data: (nullable) (type gpointer) the data model of type GtkTreeModel
 *
 * @cell must not be %NULL.
 *
 * Updates the edited cell, validating it if a validator has been configured.
 * @see: set_table_with_validator
 * @see: tree_cell_edited
 * @see: editing_started
 *
 * Returns: void
 */
void list_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data);

/**
 * tree_cell_edited:
 * @cell: (type GtkCellRendererText) the cell that has been updated - from this we can get the column number.
 * @path_string: (type const gchar) the path to the row in the tableview that will need to be updated.
 * @new_text: (type const gchar) the new text that the cell will be populated with.
 * @data: (nullable) (type gpointer) the data model of type GtkTreeModel
 *
 * @cell must not be %NULL.
 *
 * Updates the edited cell, validating it if a validator has been configured.
 * @see: set_table_with_validator
 * @see: list_cell_edited
 * @see: editing_started
 *
 * Returns: void
 */
void tree_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data);

/**
 * editing_started:
 * @cell: (type GtkCellRendererText) the cell that is being updated - from this we can get the column number.
 * @editable: (type const GtkCellEditable) whether or not the cell is editable.
 * @path: (type const gchar) the path to the row in the tableview that is being edited.
 * @data: (nullable) (type gpointer) the data model of type GtkTreeModel
 *
 * @cell must not be %NULL.
 *
 * Callback when edits start in the cell. Not implemented yet.
 * @see: list_cell_edited
 * @see: tree_cell_edited
 *
 * Returns: void
 */
void editing_started (GtkCellRenderer *cell, GtkCellEditable *editable, const gchar *path, gpointer data);

GtkTreeIter get_parent_iter(GtkTreeModel* model, GtkTreeIter child_iter, bool* has_parent);

/**
 * get_selected_tree_node:
 * @treeview: (type GtkWidget) the tree view containing the cell for which the iter is required.
 *
 * @treeview must not be %NULL.
 *
 * Returns the iter for the row that contains the selected cell.
 *
 * Returns: GtkTreeIter
 */
GtkTreeIter get_selected_tree_node(GtkWidget *treeview);

/**
 * get_selected_row_index:
 * @treeview: (type GtkWidget) the tree view containing the cell for which the index is required.
 * @istree: (type bool) whether the row is in a tree (otherwise it's in a list)
 *
 * @treeview must not be %NULL.
 *
 * Returns the index for the row that contains the selected cell.
 *
 * Returns: int
 */
int get_selected_row_index(GtkWidget *treeview, bool istree);

/**
 * delete_list_row:
 * @widget: (nullable) (type GtkWidget) the tree view containing the cell for which the index is required.
 * @treeview: (type GtkWidget) the list view containing the cell for which the index is required.
 *
 * @treeview must not be %NULL.
 *
 * Deletes the row from the list that contains the selected cell.
 *
 * Returns: void
 */
void delete_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * delete_tree_row:
 * @widget: (nullable) (type GtkWidget) the tree view containing the cell for which the index is required.
 * @treeview: (type GtkWidget) the tree view containing the cell for which the index is required.
 *
 * @treeview must not be %NULL.
 *
 * Deletes the row from the tree that contains the selected cell.
 *
 * Returns: void
 */
void delete_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 * cell_selection_function:
 * @selection: (nullable) (type GtkWidget) the tree view containing the cell which will be selected.
 * @model: (type GtkWidget) the data ,odel for the tree view.
 * @path: (type GtkTreePath) the path to the row in the tableview that is being selected.
 * @path_currently_selected: (type gboolean) Whether the cell is already  selected.
 * @userdata: (nullable) (type gpointer) .
 *
 * @selection must not be %NULL.
 * @model must not be %NULL.
 * @path must not be %NULL.
 *
 * Function called when cell is selected or loses selection. Not implemented yet.
 *
 * Returns: void
 */
gboolean cell_selection_function (GtkTreeSelection *selection,
                              GtkTreeModel *model,
                              GtkTreePath *path,
                              gboolean path_currently_selected,
                              gpointer userdata);

/**
 * create_tableview_with_model:
 * @model: (type void) a pointer to the data model for the table view.
 *
 * @model must not be %NULL.
 *
 * Creates a tableview using the supplied model.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_tableview_with_model (void* model);

/**
 * add_column_to_table:
 * @editable: (type bool) whether the table view column is editable or not.
 * @tree_store: (type bool) whether the table view column is a tree store not. The alternative is a list store
 * @model_def: (type struct model_definition) a structure containing the table view and validator. The validator may be null.
 * @title: (type const gchar) the title for the column.
 * @cell: (type GtkCellRenderer) the cell that the column will contain.
 * @column_num: (type guint) number of the column being set up.
 *
 * @cell must not be %NULL.
 *
 * Adds a column to the table provided in #tree_store.
 * @see: add_columns_to_table
 * @see: set_table_with_validator
 *
 * Returns: void
 */
void add_column_to_table (bool editable, bool tree_store, struct model_definition model_def, const gchar *title, GtkCellRenderer *cell, guint column_num, ...);

/**
 * add_column_to_table:
 * @editable: (type bool) whether the table view column is editable or not.
 * @tree_store: (type bool) whether the table view column is a tree store not. The alternative is a list store
 * @model_def: (type struct model_definition) a structure containing the table view and validator. The validator may be null.
 *
 * @model must not be %NULL.
 *
 * Adds multiple columns to the table provided in #tree_store using the parameters supplied in the arg_list
 * @see: add_column_to_table
 * @see: set_table_with_validator
 *
 * Returns: void
 */
void add_columns_to_table (bool editable, bool tree_store, struct model_definition model_def, ...);

/**
 * set_table_with_validator:
 * @validator_ptr: (nullable) (type void) function pointer to the validator.
 * @tableview: (type gpointer) the tableview for which the columns will be set up.
 *
 * @tableview must not be %NULL.
 *
 * Sets the table and adds a validator, if required.  Use in conjunction with add_columns_to_table and add_column_to_table
 * @see: add_column_to_table
 * @see: add_columns_to_table
 *
 * Returns: struct model_definition
 */
model_definition set_table_with_validator(void (*validator_ptr), gpointer tableview);

#endif
