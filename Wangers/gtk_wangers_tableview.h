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
 @brief Saves the contents of a `GtkTreeView` to a text file.
 @discussion Iterates through each row and column of the tree view model, serializing cell contents as comma-separated values. Appends a newline after each row and writes the result to the specified file.
 @param treeview A pointer to the `GtkTreeView` whose contents will be saved.
 @param filename The path to the output text file.
 @param number_of_columns The number of columns to serialize per row.
 */
void save_table_to_text_file(GtkWidget *treeview, gchar* filename, int number_of_columns);

/**
 @brief Handles double-click activation on a tree view row.
 @discussion Retrieves the value from the first column of the activated row and prints it to stdout. Useful for debugging or triggering row-specific actions.
 @param view The `GtkTreeView` that received the activation.
 @param path The path of the activated row.
 @param col The column that was activated.
 @param userdata Optional user data passed to the signal handler.
 */
void on_treeview_row_activated (GtkTreeView *view, GtkTreePath *path, GtkTreeViewColumn *col, gpointer userdata);

/**
 @brief Inserts a new row into a `GtkListStore` at the selected index.
 @discussion Uses the selected row index to insert a new row with default values. Assumes the model is a list store.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void insert_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Inserts a new row into a `GtkTreeStore` relative to the selected node.
 @discussion Inserts a new row either as a sibling or child depending on the parent context. Handles parent-child relationships and validates iterators.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void insert_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Creates a child row under the selected parent node in a `GtkTreeStore`.
 @discussion Inserts a new child row at the selected index under the current node. Assumes the model is a tree store.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void create_child_for_parent (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Appends a new row to the end of a `GtkListStore`.
 @discussion Inserts a new row with default values at the end of the list model.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void add_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Appends a new row to the root of a `GtkTreeStore`.
 @discussion Inserts a new row with default values at the top level of the tree model.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void add_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Handles cell edits in a `GtkListStore`.
 @discussion Updates the specified column of the edited row with the new text. Uses cell metadata to determine the target column.
 @param cell The cell renderer that was edited.
 @param path_string The string path of the edited row.
 @param new_text The new text to set in the cell.
 @param data A pointer to the model (`GtkTreeModel*`).
 */
void list_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data);

/**
 @brief Handles cell edits in a `GtkTreeStore`, with optional validation.
 @discussion Allocates a modifiable buffer for the new text, validates it if a validator is set, and updates the cell. Frees the buffer after use.
 @param cell The cell renderer that was edited.
 @param path_string The string path of the edited row.
 @param new_text The new text to set in the cell.
 @param data A pointer to the model (`GtkTreeModel*`).
 */
void tree_cell_edited (GtkCellRendererText *cell, const gchar *path_string, const gchar *new_text, gpointer data);

/**
 @brief Placeholder for cell editing start event.
 @discussion Currently unused. Can be extended to handle pre-edit logic or styling.
 @param cell The cell renderer being edited.
 @param editable The editable widget.
 @param path The path of the cell.
 @param data Optional user data.
 */
void editing_started (GtkCellRenderer *cell, GtkCellEditable *editable, const gchar *path, gpointer data);

/**
 @brief Retrieves the parent iterator of a given tree node.
 @discussion Computes the parent path of the given child iterator and returns the corresponding iterator. Sets a flag indicating whether a parent exists.
 @param model The tree model.
 @param child_iter The iterator of the child node.
 @param has_parent A pointer to a boolean that will be set to true if a parent exists.
 @return The parent iterator if valid; otherwise, undefined.
 */
GtkTreeIter get_parent_iter(GtkTreeModel* model, GtkTreeIter child_iter, bool* has_parent);

/**
 @brief Retrieves the currently selected node in a tree view.
 @discussion Returns the iterator of the selected row in the tree view. Assumes single selection mode.
 @param treeview The `GtkTreeView` to query.
 @return The selected `GtkTreeIter`.
 */
GtkTreeIter get_selected_tree_node(GtkWidget *treeview);

/**
 @brief Gets the index of the selected row in a tree or list view.
 @discussion Converts the selected iterator to a path and extracts the row index. Returns -1 if selection is invalid.
 @param treeview The `GtkTreeView` to query.
 @param istree `true` if the model is a `GtkTreeStore`, `false` for `GtkListStore`.
 @return The row index, or -1 if no valid selection.
 */
int get_selected_row_index(GtkWidget *treeview, bool istree);

/**
 @brief Deletes the selected row from a `GtkListStore`.
 @discussion Removes the selected row if the iterator is valid.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void delete_list_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Deletes the selected node from a `GtkTreeStore`.
 @discussion Removes the selected node if the iterator is valid.
 @param widget The triggering widget (unused).
 @param treeview The `GtkTreeView` whose model will be modified.
 */
void delete_tree_row (GtkWidget *widget, GtkWidget *treeview);

/**
 @brief Selection filter function for tree view rows.
 @discussion Allows all selection changes. Can be extended to conditionally allow or block selection.
 @param selection The tree selection object.
 @param model The tree model.
 @param path The path of the row being selected or unselected.
 @param path_currently_selected Whether the row is currently selected.
 @param userdata Optional user data.
 @return `TRUE` to allow the selection change.
 */
gboolean cell_selection_function (GtkTreeSelection *selection,
                              GtkTreeModel *model,
                              GtkTreePath *path,
                              gboolean path_currently_selected,
                              gpointer userdata);

/**
 @brief Creates a tree view widget with a model and selection filter.
 @discussion Initializes a `GtkTreeView` with the given model and sets a custom selection function. Unrefs the model after binding.
 @param model A pointer to the tree model (`GtkTreeModel*`).
 @return A pointer to the newly created `GtkTreeView`.
 */
GtkWidget* create_tableview_with_model (void* model);

/**
 @brief Adds a column to a tree or list view with editable cells and attributes.
 @discussion Configures a `GtkTreeViewColumn` with a cell renderer, title, and attribute bindings. Connects edit signals and applies validator if present.
 @param editable Whether the cell should be editable.
 @param tree_store `true` if the model is a `GtkTreeStore`, `false` for `GtkListStore`.
 @param model_def A `model_definition` struct containing the table view and validator.
 @param title The column title.
 @param cell The cell renderer to use.
 @param column_num The model column index.
 @param ... Attribute bindings in pairs: attribute name (`gchar*`), column index (`gint`), ending with `NULL`.
 */
void add_column_to_table (bool editable, bool tree_store, struct model_definition model_def, const gchar *title, GtkCellRenderer *cell, guint column_num, ...);

/**
 @brief Adds multiple text columns to a tree or list view.
 @discussion Iterates through a variable argument list of title/index pairs and adds each column using `add_column_to_table`. Each column uses a new editable text renderer and binds the "text" attribute to the specified model column. Assumes the model is either a `GtkTreeStore` or `GtkListStore`.
 @param editable Whether the cells should be editable.
 @param tree_store `true` if the model is a `GtkTreeStore`, `false` for `GtkListStore`.
 @param model_def A `model_definition` struct containing the table view and optional validator.
 @param ... A variable list of title/index pairs: column title (`gchar*`), column index (`gint`), ending with `NULL`.
 */
void add_columns_to_table (bool editable, bool tree_store, struct model_definition model_def, ...);

/**
 @brief Constructs a `model_definition` with validator and table view.
 @discussion Initializes a `model_definition` struct to associate a validator function with a specific table view. Used to enforce cell-level validation during editing.
 @param validator_ptr A pointer to a validation function accepting cell context and modifiable text.
 @param tableview A pointer to the `GtkTreeView` to be associated with the validator.
 @return A fully initialized `model_definition` struct.
 */
model_definition set_table_with_validator(void (*validator_ptr), gpointer tableview);

#endif
