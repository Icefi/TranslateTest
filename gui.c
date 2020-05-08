#include "gui.h"
#include "base.h"

void
compareFunc (GtkWidget *widget,
             gpointer   user_data
			 )
{
    struct compData *data = user_data;

    int temp = strcmp(data->engwords,gtk_entry_get_text(data->entry));
    if (temp == 0){
        data->result[data->current_key] = '+';
    } else {
        data->result[data->current_key] = '-';
    }

    word_change(data);
	gtk_label_set_text (data->labelWord,data->ruwords);
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
    set_compData(gtk_spin_button_get_value(data->counterSetter),'e',data);
    gtk_label_set_text(data->labelWord, data->ruwords);

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

void
createResults(gpointer user_data, GtkWidget* grid){
    struct compData *data = user_data;
    GtkWidget *labelResults;
    char temp[10] = {};
    // write buffers as you ga along?
    labelResults = gtk_label_new(temp);
    gtk_grid_attach (GTK_GRID (grid), labelResults, 1, 3, 1, 1);
}

void
activate (GtkApplication *app,
          gpointer        user_data)
{
    /* PREPARATIONS */
    GtkWidget *window;
    GtkWidget *gridTest, *gridMenu, *gridEnd;
    GtkWidget *buttonNext, *buttonStart;
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
    labelStart = gtk_label_new("How many questions?");
    gtk_grid_attach (GTK_GRID (gridMenu), labelStart, 0, 0, 1, 1);

    data->counterSetter = gtk_spin_button_new_with_range(1,10,1);
    gtk_grid_attach (GTK_GRID (gridMenu), data->counterSetter, 0, 1, 1, 1);

    buttonStart = gtk_button_new_with_label("Begin the test");
    g_signal_connect (buttonStart, "clicked", G_CALLBACK (testStart), data);
    gtk_grid_attach (GTK_GRID (gridMenu), buttonStart, 0, 2, 1, 1);

    /* TESTING GROUNDS */
    data->labelWord = gtk_label_new ("placeholder");
    gtk_label_set_line_wrap (GTK_LABEL (data->labelWord), TRUE);
    gtk_label_set_max_width_chars (GTK_LABEL (data->labelWord), 15);
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

    createResults(data, gridEnd);

    /* SHOW WINDOW */
    gtk_container_add (GTK_CONTAINER (window), GTK_STACK (data->pages));
    gtk_widget_show_all (window);
}