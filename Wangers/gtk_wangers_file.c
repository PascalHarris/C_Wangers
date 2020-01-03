#include "gtk_wangers_file.h"

void show_save_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters) { //struct with parent window, current filename, file data, action pointer
    GtkWidget *dialogue;
    GtkFileChooser *chooser;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
    gint response;
    
    char* existing_filepath = ((struct document*)dialogue_parameters)->filename;
    
    dialogue = gtk_file_chooser_dialog_new ("Save File", ((struct document*)dialogue_parameters)->parent_window, action,
                                            "Cancel", GTK_RESPONSE_CANCEL,
                                            "Save", GTK_RESPONSE_ACCEPT,
                                            NULL);
    chooser = GTK_FILE_CHOOSER (dialogue);
    
    gtk_file_chooser_set_do_overwrite_confirmation (chooser, TRUE);
    
    
    if (strcmp(existing_filepath, EMPTY_DOCUMENT) != 0) { // filenames match - it's a new document
        gtk_file_chooser_set_current_name (chooser, EMPTY_DOCUMENT);
    } else {
        gtk_file_chooser_set_filename (chooser, existing_filepath);
    }
    
    response = gtk_dialog_run (GTK_DIALOG (dialogue));
    if (response == GTK_RESPONSE_ACCEPT) {
        char *filepath;
        filepath = gtk_file_chooser_get_filename (chooser);
        ((struct document*)dialogue_parameters)->filename = filepath;
        gtk_window_set_title(((struct document*)dialogue_parameters)->parent_window, g_path_get_basename(filepath));
        (*((struct document*)dialogue_parameters)->save_action_ptr)(dialogue_parameters); // this needs to change
        g_free (filepath);
    }
    
    gtk_widget_destroy (dialogue);
}

void show_open_dialogue (GtkWindow *parent_window, gpointer dialogue_parameters) { //struct with parent window, current filename, file data
    //    struct document *doc = dialogue_parameters;
    GtkWidget *dialogue;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint response;
    
    //char *filename; //placeholder
    //g_print("TEST %s\n", (*doc).filename);
    
    dialogue = gtk_file_chooser_dialog_new ("Open File", ((struct document*)dialogue_parameters)->parent_window, action,
                                            "Cancel", GTK_RESPONSE_CANCEL,
                                            "Open", GTK_RESPONSE_ACCEPT,
                                            NULL);
    
    response = gtk_dialog_run (GTK_DIALOG (dialogue));
    if (response == GTK_RESPONSE_ACCEPT) {
        char *filepath;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialogue);
        filepath = gtk_file_chooser_get_filename (chooser);
        ((struct document*)dialogue_parameters)->filename = filepath;
        gtk_window_set_title(((struct document*)dialogue_parameters)->parent_window, g_path_get_basename(filepath));
        (*((struct document*)dialogue_parameters)->open_action_ptr)(dialogue_parameters); // perform the action pointed to when show open dialogue is called. call by passing the address of the open function show_open_dialogue(wn, &function ...)
        g_free (filepath);
    }
    
    gtk_widget_destroy (dialogue);
}
