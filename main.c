#include <gtk/gtk.h>
#include <stdio.h>

static void
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

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *entry;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Test");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  grid = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (window), grid);

  entry = gtk_entry_new();
  gtk_grid_attach (GTK_GRID (grid), entry, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("Next");
  g_signal_connect (button, "clicked", G_CALLBACK (print_entry), entry);

  gtk_grid_attach (GTK_GRID (grid), button, 1, 1, 1, 1);

  gtk_widget_show_all (window);

}

int main(int argc, char *argv[]){

	gtk_init (&argc, &argv);

	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.test", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return 0;
}