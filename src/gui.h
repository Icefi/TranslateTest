#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_SIZE 20

typedef struct compData {
    int countWords;
    int currentKey;
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

void testStart(GtkWidget* widget, gpointer userData);

void error(GtkWidget* app, char* errorText);

void testEnd(gpointer userData);

void destroy(GtkWidget* widget, gpointer data);

void setEng(GtkWidget* widget, gpointer userData);

void setRu(GtkWidget* widget, gpointer userData);

void compareFunc(GtkWidget* widget, gpointer userData);

void activate(GtkApplication* app, gpointer userData);

#endif /*GUI_H*/
