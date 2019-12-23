#include "gtk_wangers_window.h"

void destroy (GtkWidget *widget,gpointer data) {
    gtk_main_quit ();
}

GtkWidget* create_window (int width, int height, char* title, bool will_destroy) {
    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), title);
    gtk_window_set_default_size (GTK_WINDOW (window), width, height);
    if ( will_destroy) {
        g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);
    }
    return window;
}

void close_modal (GtkDialog *dialog, gint response_id, gpointer user_data) {
    gtk_widget_destroy (GTK_WIDGET (dialog));
}

void show_dialogue (GtkButton *button, gpointer user_data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;

    dialog = gtk_dialog_new_with_buttons (((struct about_box_definition*)user_data)->title,
                                          ((struct about_box_definition*)user_data)->window,
                                          GTK_DIALOG_MODAL,
                                          "Okay",
                                          NULL);

    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    label = gtk_label_new (((struct about_box_definition*)user_data)->about_message);
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
    gtk_container_add (GTK_CONTAINER (content_area), label);

    g_signal_connect (GTK_DIALOG (dialog),
                      "response",
                      G_CALLBACK (close_modal),
                      NULL);

    gtk_widget_show_all (dialog);
}

about_box_definition define_about_box(char* title, char* about_message, GtkWindow* window) {
    about_box_definition about_def;
    about_def.title = title;
    about_def.about_message = about_message;
    about_def.window = window;
    return about_def;
}
