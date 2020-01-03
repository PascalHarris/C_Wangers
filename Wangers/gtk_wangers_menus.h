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

/**
 * create_menubar:
 *
 * Creates a new, empty, menubar.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_menubar();

/**
 * create_menu:
 * @menubar: (type void*) The menubar to create the menu in.
 * @label: (type char*) The label for the menu.
 *
 * @menubar must not be %NULL.
 * @label must not be %NULL.
 *
 * Creates a new menu in the supplied menubar using the supplied label.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_menu(void* menubar, char* label);

/**
 * create_menuitem_with_parameters:
 * @parent_menu: (type void*) The menu to create the menu item in.
 * @label: (type char*) The label for the menu item.
 * @menuaction: (type void*) A pointer to a struct of type action_param containing the action and any parameters.
 *
 * @parent_menu must not be %NULL.
 * @label must not be %NULL.
 * @menuaction must not be %NULL.
 *
 * Creates a new menu item in the supplied menu using the supplied label, and with the supplied menuaction.
 *
 * @see set_action_with_parameter in gtk_wangers_action
 *
 * Returns: GtkWidget
 */
GtkWidget* create_menuitem_with_parameters(void* parent_menu, char* label, struct action_param menuaction);

/**
 * create_menuitem:
 * @parent_menu: (type void*) The menu to create the menu item in.
 * @label: (type char*) The label for the menu item.
 * @menu_action_ptr: (type void*) A function pointer to a menu action.
 *
 * @parent_menu must not be %NULL.
 * @label must not be %NULL.
 * @menu_action_ptr must not be %NULL.
 *
 * Creates a new menu item in the supplied menu using the supplied label, and with the supplied menu_action_ptr
 * function pointer.
 *
 * Returns: GtkWidget
 */
GtkWidget* create_menuitem(void* parent_menu, char* label, void (*menu_action_ptr)(void*));
#endif
