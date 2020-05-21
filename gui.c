#include "gui.h"
#include "base.h"

void
compareFunc (GtkWidget *widget,
             gpointer   user_data
			 )
{
    struct compData *data = user_data;
    int temp;

    if (data->mode == 'e'){
        temp = strcmp(data->ruwords,gtk_entry_get_text(data->entry));
        word_change(data);
        gtk_label_set_text (data->labelWord,data->engwords);
    } else {
        temp = strcmp(data->engwords,gtk_entry_get_text(data->entry));
        word_change(data);
        gtk_label_set_text (data->labelWord,data->ruwords);        
    }
    if (temp == 0){
        data->result[data->current_key] = '+';
    } else {
        data->result[data->current_key] = '-';
    }
    gtk_entry_set_text(data->entry,"");

    data->current_key++;
    if (data->current_key >= data->count_words){
        data->result[data->current_key] = '\0';
        testEnd(data);
    }
    return;
}

void
testStart(GtkWidget *widget,
            gpointer   user_data)
{
    struct compData *data = user_data;
    set_compData(gtk_spin_button_get_value(data->counterSetter),data);

    if (data->mode == 'e'){
        gtk_label_set_text(data->labelWord, data->engwords);
    } else {
        gtk_label_set_text(data->labelWord, data->ruwords);
    }

    gtk_stack_set_visible_child_name(data->pages,"Test");
    return;
}

void
testEnd(gpointer user_data)
{
    struct compData *data = user_data;
    gtk_stack_set_visible_child_name(data->pages,"End");
    return;
}

void destroy (GtkWidget* widget, gpointer user_data)
{
    g_application_quit(G_APPLICATION(user_data));
}

void setEng(GtkWidget* widget, gpointer user_data)
{
    struct compData *data = user_data;
    data->mode = 'e';
    return;
}

void setRu(GtkWidget* widget, gpointer user_data)
{
    struct compData *data = user_data;
    data->mode = 'r';
    return;
}

void
activate (GtkApplication *app,
          gpointer        user_data)
{
    /* PREPARATIONS */
    GtkWidget *window;
    GtkWidget *gridTest, *gridMenu, *gridEnd;
    GtkWidget *buttonNext, *buttonStart, *buttonQuit;
    GtkWidget *ruButton, *engButton;
    GtkWidget *labelEnd, *labelStart;
    struct compData* data = malloc(sizeof(struct compData));

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Test");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_window_set_resizable(GTK_WINDOW (window),FALSE);

    gridEnd = gtk_grid_new();
    gridMenu = gtk_grid_new();
    gridTest = gtk_grid_new();

    data->pages = gtk_stack_new();
    gtk_stack_add_named(GTK_STACK (data->pages),gridMenu,"Menu");
    gtk_stack_add_named(GTK_STACK (data->pages),gridTest,"Test");
    gtk_stack_add_named(GTK_STACK (data->pages),gridEnd,"End");

    /* MAIN MENU */
    labelStart = gtk_label_new("Сколько вопросов?\nС какого переводим?");
    gtk_grid_attach (GTK_GRID (gridMenu), labelStart, 0, 0, 1, 1);

    data->counterSetter = gtk_spin_button_new_with_range(1,10,1);
    gtk_grid_attach (GTK_GRID (gridMenu), data->counterSetter, 0, 1, 1, 1);

    data->mode = 'r';
    ruButton = gtk_radio_button_new_with_label(NULL,"Русский");
    engButton = gtk_radio_button_new_with_label_from_widget(ruButton,"Английский");
    g_signal_connect (ruButton, "toggled", G_CALLBACK (setRu), data);
    g_signal_connect (engButton, "toggled", G_CALLBACK (setEng), data);
    gtk_grid_attach (GTK_GRID (gridMenu), ruButton, 0, 2, 1, 1);
    gtk_grid_attach (GTK_GRID (gridMenu), engButton, 1, 2, 1, 1);

    buttonStart = gtk_button_new_with_label("Begin the test");
    g_signal_connect (buttonStart, "clicked", G_CALLBACK (testStart), data);
    gtk_grid_attach (GTK_GRID (gridMenu), buttonStart, 0, 3, 1, 1);

    /* TESTING GROUNDS */
    data->labelWord = gtk_label_new ("placeholder");
    gtk_label_set_line_wrap (GTK_LABEL (data->labelWord), TRUE);
    gtk_label_set_max_width_chars (GTK_LABEL (data->labelWord), MAX_WORD_SIZE);
    gtk_grid_attach (GTK_GRID (gridTest), data->labelWord, 0, 0, 2, 1);

    data->entry = gtk_entry_new();
    g_signal_connect (data->entry, "activate", G_CALLBACK (compareFunc), data);
    gtk_grid_attach (GTK_GRID (gridTest), data->entry, 0, 1, 2, 1);

    buttonNext = gtk_button_new_with_label ("Next");
    g_signal_connect (buttonNext, "clicked", G_CALLBACK (compareFunc), data);
    gtk_grid_attach (GTK_GRID (gridTest), buttonNext, 1, 2, 1, 1);

    /* SCORING */
    labelEnd = gtk_label_new("Результаты");
    gtk_grid_attach (GTK_GRID (gridEnd), labelEnd, 0, 0, 2, 1);

    buttonQuit = gtk_button_new_with_label("Выход");
    g_signal_connect (buttonQuit, "clicked", G_CALLBACK (destroy), app);
    gtk_grid_attach (GTK_GRID (gridEnd), buttonQuit, 0, 2, 1, 1);

    /* SHOW WINDOW */
    gtk_container_add (GTK_CONTAINER (window), GTK_STACK (data->pages));
    gtk_widget_show_all (window);
    return;
}