#include "wangers/gtk_wangers.h"

typedef struct SearchBar {
    GtkWidget *search_entry;
    GtkWidget *search_button;
    GtkWidget *next_button;
    GtkWidget *close_button;
    GtkWidget *text_view;
} SearchBar;

typedef struct FileData {
    GtkWidget *text_view;
    GtkTextBuffer *buffer;
    GtkWidget *statusbar;
} FileData;

#pragma mark - Create file, open file, save file functions

void create_file (GtkWidget *widget, document *doc) {
    struct FileData* filedataptr = doc->filedata;
    gtk_widget_show(filedataptr->text_view);
    gtk_widget_show(filedataptr->statusbar);
    gtk_window_set_title(GTK_WINDOW(doc->parent_window), EMPTY_DOCUMENT);
    gtk_text_buffer_set_text(filedataptr->buffer, "", -1);
}

void open_file(document *doc) {
    struct FileData* filedataptr = doc->filedata;
    gchar *contents;
    g_file_get_contents(doc->filename, &contents, NULL, NULL);
    gtk_widget_show(filedataptr->text_view);
    gtk_widget_show(filedataptr->statusbar);
    gtk_text_buffer_set_text(filedataptr->buffer, contents, -1);
}

void save_file(document *doc) {
    struct FileData* filedataptr = doc->filedata;
    GtkTextIter start, end;
    GtkTextBuffer *buffer = filedataptr->buffer;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *contents = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    g_file_set_contents(doc->filename, contents, -1, NULL);
}

#pragma mark - Functions related to search-bar
void find (GtkTextView *text_view, const gchar *text, GtkTextIter *iter) {
    GtkTextIter block_start, block_end;
    GtkTextMark *last_pos;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text_view));
    gboolean found = gtk_text_iter_forward_search (iter, text, 0, &block_start, &block_end, NULL);
    
    if (found) {
        gtk_text_buffer_select_range (buffer, &block_start, &block_end);
        last_pos = gtk_text_buffer_create_mark (buffer, "last_pos", &block_end, FALSE);
        gtk_text_view_scroll_mark_onscreen (text_view, last_pos);
    }
}

void close_button_clicked (GtkWidget *sender, SearchBar *search_bar) {
    gtk_widget_hide(search_bar->search_entry);
    gtk_widget_hide(search_bar->search_button);
    gtk_widget_hide(search_bar->next_button);
    gtk_widget_hide(search_bar->close_button);
}

void find_menu_selected(GtkWidget *sender, SearchBar *search_bar) {
    gtk_widget_show(search_bar->search_entry);
    gtk_widget_show(search_bar->search_button);
    gtk_widget_show(search_bar->next_button);
    gtk_widget_show(search_bar->close_button);
}

void search_button_clicked (GtkWidget *sender, SearchBar *search_bar) {
    const gchar *text = gtk_entry_get_text (GTK_ENTRY (search_bar->search_entry));
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (search_bar->text_view));
    GtkTextIter iter;
    
    gtk_text_buffer_get_start_iter (buffer, &iter);
    find (GTK_TEXT_VIEW (search_bar->text_view), text, &iter);
}

void next_button_clicked (GtkWidget *sender, SearchBar *search_bar) {
    const gchar *text = gtk_entry_get_text (GTK_ENTRY (search_bar->search_entry));
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (search_bar->text_view));
    GtkTextMark *last_pos = gtk_text_buffer_get_mark (buffer, "last_pos");
    GtkTextIter iter;
    
    if (last_pos == NULL) {
        search_button_clicked (NULL, search_bar);
        return;
    }
    
    gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos);
    find (GTK_TEXT_VIEW (search_bar->text_view), text, &iter);
}

#pragma mark - Menu item functions
void select_font(GtkWidget *widget, document *doc) {
    struct FileData* filedataptr = doc->filedata;
    GtkWidget *chooser = gtk_font_chooser_dialog_new("Select Font", doc->parent_window);
    GtkResponseType result = gtk_dialog_run(GTK_DIALOG(chooser));
    
    if (result == GTK_RESPONSE_OK || result == GTK_RESPONSE_APPLY) {
        PangoFontDescription *font_desc = gtk_font_chooser_get_font_desc(GTK_FONT_CHOOSER(chooser));
        gtk_widget_override_font(GTK_WIDGET(filedataptr->text_view), font_desc);
        pango_font_description_free(font_desc);
    }
    gtk_widget_destroy(chooser);
}

#pragma mark - Cut copy and paste functions

void copy_to_clipboard(GtkWidget *sender, GtkTextBuffer *buffer){
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_NONE);
    gtk_text_buffer_copy_clipboard(buffer, clipboard);
}

void cut_to_clipboard(GtkWidget *sender, GtkTextBuffer *buffer){
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_NONE);
    gtk_text_buffer_cut_clipboard(buffer, clipboard, TRUE);
}

void paste_from_clipboard(GtkWidget *sender, GtkTextBuffer *buffer){
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_NONE);
    gtk_text_buffer_paste_clipboard(buffer, clipboard, NULL, TRUE);
}

#pragma mark - Text buffer functions
void update_statusbar(GtkTextBuffer *buffer, GtkStatusbar *statusbar) {
    GtkTextIter iter;
    
    gtk_statusbar_pop(statusbar, 0);
    
    gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));
    
    gint row = gtk_text_iter_get_line(&iter);
    gint col = gtk_text_iter_get_line_offset(&iter);
    
    gchar *msg = g_strdup_printf("Column: %d Line: %d", col+1, row+1);
    
    gtk_statusbar_push(statusbar, 0, msg);
    
    g_free(msg);
}

void mark_set_callback(GtkTextBuffer *buffer, const GtkTextIter *new_location, GtkTextMark *mark, gpointer data) {
    update_statusbar(buffer, GTK_STATUSBAR(data));
}

#pragma mark - Main

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    
    // Window and layout setup
    GtkWidget *window = create_window(640, 480, "Tedditor", true);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    GtkWidget *layout_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    GtkWidget *searchbar_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_container_add(GTK_CONTAINER(window), layout_box);
    
    // Document setup
    GtkWidget *text_view = gtk_text_view_new ();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    FileData file_data;
    file_data.buffer = buffer;
    file_data.text_view = text_view;
    struct document this_document = build_document_with_characteristics(GTK_WINDOW(window), &save_file,
                                                                        &open_file, EMPTY_DOCUMENT, &file_data);
    
    // Menu and Searchbar setup
    struct SearchBar search_bar;
    GtkWidget *menubar = create_menubar();
    GtkAccelGroup *shortcut_group = create_shortcut_group(window);
    
    GtkWidget *fileMenu = create_menu(menubar, "File");
    create_menuitem_with_parameters_and_shortcut(fileMenu, "New", set_action_with_parameter(&create_file, &this_document), shortcut_group, 'n');
    create_menuitem_with_parameters_and_shortcut(fileMenu, "Open", set_action_with_parameter(&show_open_dialogue, &this_document), shortcut_group, 'o');
    create_menuitem_with_parameters_and_shortcut(fileMenu, "Save", set_action_with_parameter(&show_save_dialogue, &this_document), shortcut_group, 's');
    create_menuitem_with_parameters_and_shortcut(fileMenu, "Quit", set_action_with_parameter(&gtk_main_quit, NULL), shortcut_group, 'q');
    
    GtkWidget *editMenu = create_menu(menubar, "Edit");
    create_menuitem_with_parameters_and_shortcut(editMenu, "Cut", set_action_with_parameter(&cut_to_clipboard, &buffer), shortcut_group, 'x');
    create_menuitem_with_parameters_and_shortcut(editMenu, "Copy", set_action_with_parameter(&copy_to_clipboard, &buffer), shortcut_group, 'c');
    create_menuitem_with_parameters_and_shortcut(editMenu, "Paste", set_action_with_parameter(&paste_from_clipboard, &buffer), shortcut_group, 'v');
    
    GtkWidget *optionsMenu = create_menu(menubar, "Options");
    create_menuitem_with_parameters_and_shortcut(optionsMenu, "Font", set_action_with_parameter(&select_font, &this_document), shortcut_group, 't');
    create_menuitem_with_parameters_and_shortcut(optionsMenu, "Find", set_action_with_parameter(&find_menu_selected, &search_bar), shortcut_group, 'f');
    
    struct about_box_definition about_def = define_about_box("About Tedditor",
                                                             "Tedditor\n---------\n\nThe GTKWangers Example Text Editor\n\n2019 45RPM Software www.45rpmsoftware.com\nBased on sedit by www.incessantmeraki.com\nWritten by Pascal Harris\n\n",
                                                             GTK_WINDOW (window));
    GtkWidget *helpMenu = create_menu(menubar, "Help");
    create_menuitem_with_parameters(helpMenu, "About", set_action_with_parameter(&show_dialogue, &about_def));
    
    gtk_container_add(GTK_CONTAINER (layout_box), menubar);
    
    GtkWidget *scrollview = create_scrollview_with_object(text_view);
    gtk_container_add(GTK_CONTAINER (layout_box), scrollview);
    
    search_bar.text_view = text_view;
    search_bar.search_entry = gtk_entry_new ();
    gtk_container_add(GTK_CONTAINER (searchbar_box), search_bar.search_entry);
    
    search_bar.search_button = create_button("Search", G_CALLBACK(search_button_clicked), &search_bar);
    gtk_container_add(GTK_CONTAINER (searchbar_box), search_bar.search_button);
    
    search_bar.next_button = create_button("Next", G_CALLBACK(next_button_clicked), &search_bar);
    gtk_container_add(GTK_CONTAINER (searchbar_box), search_bar.next_button);
    
    search_bar.close_button = create_button("Close", G_CALLBACK(close_button_clicked), &search_bar);
    gtk_container_add(GTK_CONTAINER (searchbar_box), search_bar.close_button);
    
    gtk_container_add(GTK_CONTAINER (layout_box), searchbar_box);
    
    // Status bar setup
    GtkWidget *statusbar = gtk_statusbar_new();
    gtk_container_add(GTK_CONTAINER (layout_box), statusbar);
    file_data.statusbar = statusbar;
    
    g_signal_connect(buffer, "changed", G_CALLBACK(update_statusbar), statusbar);
    g_signal_connect_object(buffer, "mark_set", G_CALLBACK(mark_set_callback), statusbar, 0);
    
    gtk_widget_show_all(window);
    
    gtk_widget_hide(text_view);
    close_button_clicked(NULL,&search_bar);
    
    gtk_widget_hide(statusbar);
    update_statusbar(buffer, GTK_STATUSBAR(statusbar));
    
    gtk_main();
    
    return 0;
}
