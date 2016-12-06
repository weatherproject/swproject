#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *entry, *textview;
} Widgets;

static void insert_text (GtkButton*, Widgets*);
static void retrieve_text (GtkButton*, Widgets*);

int main (int argc,char *argv[])
{
 	GtkWidget *window, *scrolled_win, *hbox, *vbox, *insert, *retrieve;
	GtkWidget *label;
	GtkWidget *check;
	Widgets *w = g_slice_new (Widgets);
	Widgets *w1 = g_slice_new (Widgets);
	gtk_init (&argc, &argv);

	/*window*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Text Iterators");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	//gtk_widget_set_size_request (window, 1, 200);
	gtk_widget_set_usize( GTK_WIDGET (window), 400, 300);//크기 
	vbox = gtk_vbox_new (FALSE, 5);
	/*"city" label*/
	label = gtk_label_new("도시");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*button*/
	insert = gtk_button_new_with_label ("Insert Text");
	retrieve = gtk_button_new_with_label ("Get Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (insert_text),(gpointer) w);
	g_signal_connect (G_OBJECT (retrieve), "clicked",G_CALLBACK (retrieve_text),(gpointer) w);
	/*text*/
	w->textview = gtk_text_view_new ();
	w->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w->textview);
	hbox = gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), w->entry);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), insert);
//	gtk_box_pack_start_defaults (GTK_BOX (hbox), retrieve);
	/*쌓기*/ 
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);

	/*"day" label*/
	label = gtk_label_new("몇일후");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*button*/
	insert = gtk_button_new_with_label ("Insert Text");
	retrieve = gtk_button_new_with_label ("Get Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (insert_text),(gpointer) w1);
	g_signal_connect (G_OBJECT (retrieve), "clicked",G_CALLBACK (retrieve_text),(gpointer) w1);
	/*text*/
	w1->textview = gtk_text_view_new ();
	w1->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w1->textview);
	hbox = gtk_hbox_new (FALSE, 5);	
	gtk_box_pack_start_defaults (GTK_BOX (hbox), w1->entry);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), insert);
	gtk_box_pack_start_defaults (GTK_BOX (hbox), retrieve);
	/*쌓기*/ 
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);

	/*checkbox*/
	hbox = gtk_hbox_new (FALSE, 5);	
	/*am checkbox*/
	check = gtk_check_button_new_with_label("오전");//editable라벨 붙은  check button
	gtk_box_pack_start (GTK_BOX (hbox), check, TRUE, TRUE, 0);//hbox에 첨가 
		//gtk_signal_connect (GTK_OBJECT(check), "toggled",GTK_SIGNAL_FUNC(entry_toggle_editable),NULL);//check이벤트 
		//gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), TRUE);
	gtk_widget_show (check);
	/*pm checkbox*/
	check = gtk_check_button_new_with_label("오후");
	gtk_box_pack_start (GTK_BOX (hbox), check, TRUE, TRUE, 0);
		//gtk_signal_connect (GTK_OBJECT(check), "toggled",GTK_SIGNAL_FUNC(entry_toggle_visibility), NULL);
		//gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), TRUE);
	gtk_widget_show (check);
	gtk_container_add (GTK_CONTAINER (vbox), hbox);
	gtk_widget_show (hbox);

	gtk_container_add (GTK_CONTAINER (window), vbox);

	gtk_widget_show_all (window);

	gtk_main();
    return 0;
}

/* Insert the text from the GtkEntry into the GtkTextView. */
static void
insert_text (GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));

	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	printf("Entry contents: %s\n", text);

}

/* Retrieve the selected text from the GtkTextView and display it
* to the user. */
static void
retrieve_text (GtkButton *button,
Widgets *w)
{
GtkTextBuffer *buffer;
GtkTextIter start, end;
gchar *text;

buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (w->textview));
gtk_text_buffer_get_selection_bounds (buffer, &start, &end);
text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);

g_print ("%s\n", text);
}
