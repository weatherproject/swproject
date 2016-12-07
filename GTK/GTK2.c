#include <gtk/gtk.h>
char *city;
char *day;
typedef struct
{
	GtkWidget *entry, *textview;
	const gchar *text_out;
} Widgets;

void button_am (GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	
	//w->text_out=text;
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	text=city;
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" ";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=day;
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text="후의 오전 날씨:";
	gtk_text_buffer_insert (buffer, &iter, text, -1);




	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
	

}
/* Insert the text from the GtkEntry into the GtkTextView. */
void button_pm (GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	
	//w->text_out=text;
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	text=city;
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" ";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=day;
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text="후의 오후 날씨:";
	gtk_text_buffer_insert (buffer, &iter, text, -1);


	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
	

}

void insert_text (GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	//w->text_out=text;
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" 입력하셨습니다";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
	

}

void city_text (GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	//w->text_out=text;
	city=text;
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" 입력하셨습니다";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
	

}
void day_text(GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	//w->text_out=text;
	day=text;
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" 입력하셨습니다";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
//	printf("Entry contents: %s\n", what);
	//printf("Entry contents: %s\n", text);
	

}

int main (int argc,char *argv[])
{
 	GtkWidget *window, *scrolled_win, *hbox, *vbox, *insert;
	GtkWidget *label;
	GtkWidget *button;
	Widgets *w_city = g_slice_new (Widgets);
	Widgets *w_day = g_slice_new (Widgets);
	Widgets *w_weather = g_slice_new (Widgets);
	Widgets *w_am = g_slice_new (Widgets);
	Widgets *w_pm = g_slice_new (Widgets);
	gtk_init (&argc, &argv);

	/*window*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Weather");
	gtk_signal_connect(GTK_OBJECT (window), "delete_event",(GtkSignalFunc) gtk_exit, NULL);//엑스 눌렀을때 나가라 
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_widget_set_usize( GTK_WIDGET (window), 400, 400);//크기 
	vbox = gtk_vbox_new (FALSE, 5);
	/*"city" label*/
	label = gtk_label_new("도시");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*button*/
	insert = gtk_button_new_with_label ("Insert Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (city_text),(gpointer) w_city);
	/*text*/
	w_city->textview = gtk_text_view_new ();
	w_city->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win),w_city->textview);
	hbox = gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start_defaults (GTK_BOX (hbox),w_city->entry);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), insert);
	/*쌓기*/ 
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);
	/*"day" label*/
	label = gtk_label_new("몇일후");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*button*/
	insert = gtk_button_new_with_label ("Insert Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (day_text),(gpointer) w_day);
	/*text*/
	w_day->textview = gtk_text_view_new ();
	w_day->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w_day->textview);
	hbox = gtk_hbox_new (FALSE, 5);	
	gtk_box_pack_start_defaults (GTK_BOX (hbox), w_day->entry);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), insert);
	/*쌓기*/ 
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);
	/*checkbox*/
	hbox = gtk_hbox_new (FALSE, 5);	
	/*am checkbox*/
	button = gtk_button_new_with_label ("am");
	g_signal_connect(GTK_OBJECT (button), "clicked",G_CALLBACK(button_am),(gpointer) w_weather);
	gtk_box_pack_start (GTK_BOX (hbox), button, TRUE, TRUE, 0);//hbox에 첨가
	//gtk_container_add (GTK_CONTAINER (vbox), hbox); 
	/*pm checkbox*/
	button = gtk_button_new_with_label ("pm");
	g_signal_connect (GTK_OBJECT (button), "clicked",G_CALLBACK(button_pm),(gpointer) w_weather);
	gtk_box_pack_start (GTK_BOX (hbox), button, TRUE, TRUE, 0);//hbox에 첨가
	gtk_container_add (GTK_CONTAINER (vbox), hbox); 
	/*weather_text*/
	w_weather->textview = gtk_text_view_new ();
	w_weather->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w_weather->textview);
	/*쌓기*/ 
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);

	/*닫기 */
	button = gtk_button_new_with_label ("Close");
	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",GTK_SIGNAL_FUNC(gtk_exit),GTK_OBJECT (window));
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);
    
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show_all (window);

	//printf("Entry contents: %s\n", w_city->text_out);
	gtk_main();

    return 0;
}

 
