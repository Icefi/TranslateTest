#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

void
print_entry (GtkWidget *widget,
             gpointer   data
			 );
             
const gchar*
getNextWord();

void
activate (GtkApplication *app,
          gpointer        user_data);

#endif /*GUI_H*/