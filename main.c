#include "gtk/gtk.h"

void welcome(GtkButton *button, gpointer data) {
    /* виджеты */
    GtkWidget *dialog;
    GtkWidget *label;
    GtkWidget *content_area;

    /* создать диалог */
    dialog = gtk_dialog_new_with_buttons("Learning GTK",
                                         NULL,
                                         GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                         GTK_STOCK_OK,
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);

    /* получить контейнер, в который будем пихать метку */
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    
    /* сама метка */
    label = gtk_label_new("Hi user!");
    gtk_container_add(GTK_CONTAINER(content_area), label);
    gtk_widget_show(label);

    /* запускаем диалог */
    gtk_dialog_run(GTK_DIALOG(dialog));
    /* а потом прячем */
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    
    /* запускаем GTK+ */
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* дать окну заголовок */
    gtk_window_set_title(GTK_WINDOW(window), "Learning GTK");

    /* установить внутренние границы (читайте ниже) */
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
   
    button = gtk_button_new_with_label("Hello GTK!");
    gtk_container_add(GTK_CONTAINER(window), button);
    
    gtk_widget_show_all(window);
    
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(welcome), NULL);
    
    /* передаём управление GTK+ */
    gtk_main();

    return 0;
}
