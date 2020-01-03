#include "gtk_wangers_widget.h"

GtkWidget* create_button (char* title, void* callback, void* data) {
    GtkWidget *button;
    button = gtk_button_new_with_label (title);
    g_signal_connect (button, "clicked", callback, data);
    return button;
}
