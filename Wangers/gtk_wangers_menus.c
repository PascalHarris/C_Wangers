#include "gtk_wangers_menus.h"

GtkWidget* create_menubar() {
    GtkWidget *menubar = gtk_menu_bar_new();
    return menubar;
}

GtkWidget* create_menu(void* menubar, char* label) {
    GtkWidget *menu = gtk_menu_new();
    GtkWidget *menuname = gtk_menu_item_new_with_label(label);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuname), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuname);
    return menu;
}

GtkWidget* create_menuitem_with_parameters(void* parent_menu, char* label, struct action_param menuaction) {
    GtkWidget *menuitem = gtk_menu_item_new_with_label(label);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent_menu), menuitem);
    if (menuaction.action_ptr != NULL) {
        //if (menuaction.parameter != NULL) {
        //g_print("<%s>",((struct document*)menuaction.parameter)->filename);
        //(*((struct document*)menuaction.parameter)->save_action_ptr)("");
        //}
        g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(menuaction.action_ptr), menuaction.parameter);
    }
    return menuitem;
}

GtkWidget* create_menuitem(void* parent_menu, char* label, void (*menu_action_ptr)(void*)) {
    GtkWidget *menuitem = gtk_menu_item_new_with_label(label);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent_menu), menuitem);
    if ((*menu_action_ptr) != NULL) {
        g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK((*menu_action_ptr)), NULL);
    }
    return menuitem;
}
