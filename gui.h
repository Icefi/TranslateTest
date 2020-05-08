#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include <string.h>

typedef struct compData{
    int count_words;
    int current_key;
    char* engwords;
    char* ruwords;
    GtkWidget *entry;
    GtkWidget *pages;
    GtkWidget *labelWord;
    GtkWidget *counterSetter;
    char* result;
    char mode;
}compData;

void
testStart(GtkWidget *widget,
            gpointer   user_data);

void
testEnd(gpointer user_data);

void
compareFunc (GtkWidget *widget,
             gpointer   user_data
			 );

void
createResults(gpointer user_data, GtkWidget* grid);

void
activate (GtkApplication *app,
          gpointer        user_data);

#endif /*GUI_H*/