#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

typedef struct comparasionData{
    GtkWidget *entry;
}comparasionData;

void
print_entry (GtkWidget *widget,
             gpointer   data
			 );
             
gchar*
getNextWord();

void
activate (GtkApplication *app,
          gpointer        user_data);

#endif /*GUI_H*/