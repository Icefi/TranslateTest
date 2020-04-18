#include "gui.h"

void
print_entry (GtkWidget *widget,
             gpointer   data
			 )
{
	GtkEntryBuffer *entryText;

	entryText = gtk_entry_get_buffer(data);
	g_print (gtk_entry_buffer_get_text(entryText));
	g_print ("\n");

	gtk_entry_buffer_delete_text(entryText,0,-1);
}

const gchar*
getNextWord(){
    gchar* string = "Cлово";
    /* go to the next word */
    return string;
}

void
activate (GtkApplication *app,
          gpointer        user_data)
{
    /* VARIABLES */
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *buttonNext;
    GtkWidget *entry;
    GtkWidget *labelWord;

    const gchar* wordlist[2] = {getNextWord(),getNextWord()};
    int i = 0;

    /* WINDOW */
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Test");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    /* GRID */
    grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);

    /* TARGET WORD */
    labelWord = gtk_label_new (wordlist[i]);
    gtk_label_set_line_wrap (GTK_LABEL (labelWord), TRUE);
    gtk_label_set_max_width_chars (GTK_LABEL (labelWord), 15);
    gtk_grid_attach (GTK_GRID (grid), labelWord, 0, 0, 1, 2);

    /* ENTRY */
    entry = gtk_entry_new();
    g_signal_connect (entry, "activate", G_CALLBACK (print_entry), entry);
    gtk_grid_attach (GTK_GRID (grid), entry, 0, 3, 1, 1);

    /* BUTTON */
    buttonNext = gtk_button_new_with_label ("Next");
    g_signal_connect (buttonNext, "clicked", G_CALLBACK (print_entry), entry);
    gtk_grid_attach (GTK_GRID (grid), buttonNext, 1, 4, 1, 1);

    gtk_widget_show_all (window);

}