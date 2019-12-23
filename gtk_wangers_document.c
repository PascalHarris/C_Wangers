#include "gtk_wangers_document.h"

document build_document_with_characteristics(GtkWindow *parent_window,
                                             void (*save_action_ptr),
                                             void (*open_action_ptr),
                                             gpointer filename,
                                             gpointer filedata) {
    struct document doc;
    doc.parent_window = parent_window;
    doc.save_action_ptr = save_action_ptr;
    doc.open_action_ptr = open_action_ptr;
    doc.filename = filename;
    doc.filedata = filedata;
    
    return doc;
}
