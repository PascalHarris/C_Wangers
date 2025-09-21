//
//  gtk_wangers_menus.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef MENUS_H_
#define MENUS_H_
#include <gtk/gtk.h>
#include "gtk_wangers.h"

struct action_param; // forward declaration to suppress error.

/**
 @brief Creates a new GTK menu bar widget.
 @discussion Initializes and returns a top-level `GtkMenuBar` suitable for use in window layouts.
 @return A pointer to the newly created `GtkMenuBar`.
 */
GtkWidget* create_menubar();

/**
 @brief Creates a menu and attaches it to a menu bar with a labeled item.
 @discussion Adds a labeled menu item to the given menu bar and sets its submenu to a newly created `GtkMenu`. Useful for building hierarchical menus.
 @param menubar A pointer to the `GtkMenuBar` to which the menu will be attached.
 @param label The label for the top-level menu item.
 @return A pointer to the newly created `GtkMenu` (the submenu).
 */
GtkWidget* create_menu(void* menubar, char* label);

/**
 @brief Adds a keyboard shortcut to a menu item.
 @discussion Registers a Ctrl+<key> accelerator for the given menu item using the provided accelerator group.
 @param menu_item The menu item to which the shortcut will be added.
 @param shortcut_group The `GtkAccelGroup` managing the shortcut bindings.
 @param shortcut The character key to bind (e.g., `'S'` for Ctrl+S).
 */
void add_shortcut_to_menuitem(GtkWidget* menu_item, GtkAccelGroup* shortcut_group, char shortcut);

/**
 @brief Creates a menu item with an action and a keyboard shortcut.
 @discussion Combines `create_menuitem_with_parameters` and `add_shortcut_to_menuitem` to produce a menu item with both behavior and shortcut binding.
 @param parent_menu The parent `GtkMenu` to which the item will be appended.
 @param label The label for the menu item.
 @param menuaction An `action_param` struct containing the callback and its parameter.
 @param shortcut_group The `GtkAccelGroup` managing the shortcut bindings.
 @param shortcut The character key to bind (e.g., `'O'` for Ctrl+O).
 @return A pointer to the newly created `GtkMenuItem`.
 */
GtkWidget* create_menuitem_with_parameters_and_shortcut(void* parent_menu, char* label, struct action_param menuaction, GtkAccelGroup* shortcut_group, char shortcut);

/**
 @brief Creates a menu item with an associated action.
 @discussion Appends a labeled item to the parent menu and connects its "activate" signal to the provided callback with its parameter.
 @param parent_menu The parent `GtkMenu` to which the item will be appended.
 @param label The label for the menu item.
 @param menuaction An `action_param` struct containing the callback and its parameter.
 @return A pointer to the newly created `GtkMenuItem`.
 */
GtkWidget* create_menuitem_with_parameters(void* parent_menu, char* label, struct action_param menuaction);

/**
 @brief Creates a menu item with a simple callback.
 @discussion Appends a labeled item to the parent menu and connects its "activate" signal to the provided callback. No parameter is passed to the callback.
 @param parent_menu The parent `GtkMenu` to which the item will be appended.
 @param label The label for the menu item.
 @param menu_action_ptr A pointer to the callback function to invoke on activation.
 @return A pointer to the newly created `GtkMenuItem`.
 */
GtkWidget* create_menuitem(void* parent_menu, char* label, void (*menu_action_ptr)(void*));

/**
 @brief Creates and attaches a keyboard shortcut group to a window.
 @discussion Initializes a `GtkAccelGroup` and binds it to the specified window. This group can be used to manage keyboard shortcuts for menu items.
 @param window A pointer to the `GtkWidget` representing the window.
 @return A pointer to the newly created `GtkAccelGroup`.
 */
GtkAccelGroup* create_shortcut_group(GtkWidget* window);

#endif
