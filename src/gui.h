#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 20

typedef struct compData {
    int count_words;
    int current_key;
    char engwords[10][4 * MAX_WORD_SIZE + 1];
    char ruwords[10][4 * MAX_WORD_SIZE + 1];
    GtkWidget* entry;
    GtkWidget* pages;
    GtkWidget* labelWord;
    GtkWidget* counterSetter;
    GtkWidget *labelQ, *labelA, *labelResults;
    char *qString, *aString, *resultString;
    char mode;
} compData;

void testStart(GtkWidget* widget, gpointer user_data);

void testEnd(gpointer user_data);

void destroy(GtkWidget* widget, gpointer data);

void setEng(GtkWidget* widget, gpointer user_data);

void setRu(GtkWidget* widget, gpointer user_data);

void compareFunc(GtkWidget* widget, gpointer user_data);

void activate(GtkApplication* app, gpointer user_data);

#endif /*GUI_H*/