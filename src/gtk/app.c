#include "gtk.h"
#include "app.h"

static void activate(GtkApplication *app){
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Libreforge");
	gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);
	gtk_window_maximize(GTK_WINDOW(window));
	gtk_widget_show_all(window);
}

int app_init(int argc, char *argv[]){
	GtkApplication *app;
	int status;

	gtk_init(&argc, &argv);

	app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run (G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
