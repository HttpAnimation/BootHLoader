#include <gtk/gtk.h>

static void on_icon_click(GtkWidget *widget, gpointer data) {
    g_print("Icon clicked!\n");
}

static GtkWidget* create_icon(const gchar *icon_name) {
    GtkWidget *image = gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_DIALOG);
    GtkWidget *event_box = gtk_event_box_new();

    gtk_container_add(GTK_CONTAINER(event_box), image);
    g_signal_connect(G_OBJECT(event_box), "button-press-event", G_CALLBACK(on_icon_click), NULL);

    gtk_widget_set_events(event_box, GDK_BUTTON_PRESS_MASK);
    gtk_widget_show_all(event_box);

    return event_box;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *dock;
    
    GtkSettings *settings = gtk_settings_get_default();
    g_object_set(settings, "gtk-application-prefer-dark-theme", TRUE, NULL);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "macOS-like Desktop");
    gtk_window_fullscreen(GTK_WINDOW(window));

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create a dock like macOS
    dock = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_end(GTK_BOX(vbox), dock, FALSE, FALSE, 0);
    gtk_widget_set_halign(dock, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(dock, GTK_ALIGN_END);
    gtk_style_context_add_class(gtk_widget_get_style_context(dock), "dock");

    // Add icons to the dock
    GtkWidget *icon;
    icon = create_icon("system-file-manager");
    gtk_container_add(GTK_CONTAINER(dock), icon);

    icon = create_icon("utilities-terminal");
    gtk_container_add(GTK_CONTAINER(dock), icon);

    icon = create_icon("web-browser");
    gtk_container_add(GTK_CONTAINER(dock), icon);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.macoslike", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
