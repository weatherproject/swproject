#include <gtk/gtk.h>
extern typedef struct
{
	GtkWidget *entry, *textview;
	char *text_out;

} Widgets;
//Widgets *w_city = g_slice_new (Widgets);
//Widgets *w_day = g_slice_new (Widgets);
//Widgets *w_weather = g_slice_new (Widgets);
void city_set();
void city_text (GtkButton *button,Widgets *w);
void day_text(GtkButton *button,Widgets *w);
void button_am (GtkButton *button,Widgets *w);
void button_pm (GtkButton *button,Widgets *w);
void window_setting();
void day_set();
void time_set();
void close_set();
extern GtkWidget *window, *scrolled_win, *hbox_city,*hbox_day,*hbox_time, *vbox, *insert;
extern GtkWidget *label;
extern GtkWidget *button;

//extern const gchar *city;
//extern const gchar *day;
extern const gchar *city;
extern const gchar *day;
extern int a_am,b_am,c_am;
extern int a_pm,b_pm,c_pm;
//extern char *c="hello";
