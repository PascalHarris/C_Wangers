#include "gtk_wangers_layout.h"

//object to be put in container
GtkWidget* create_container_with_rect (void* object, int x, int y, int width, int height) {
    GtkWidget *container = gtk_fixed_new();
    gtk_fixed_put (GTK_FIXED (container), object, x, y);
    gtk_widget_set_size_request(object, width, height);
    return container;
}

//object to be put in container
GtkWidget* create_scrollview_with_object (void* object) {
    GtkWidget *scrollview = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add (GTK_CONTAINER (scrollview), object);
    gtk_widget_set_hexpand(scrollview, TRUE);
    gtk_widget_set_vexpand(scrollview, TRUE);
    return scrollview;
}
