#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"
typedef struct
{
	GtkWidget *entry, *textview;
	char *text_out;

} Widgets;


GtkWidget *window, *scrolled_win, *hbox_city,*hbox_day,*hbox_time, *vbox, *insert;
GtkWidget *label;
GtkWidget *button;

//const gchar *city;
//const gchar *day;
const gchar *city;
const gchar *day;
//const gchar *c="hello";	
//const gchar *compare="서울";
int a_am,b_am,c_am;
int a_pm,b_pm,c_pm;

void city_set();
void city_text (GtkButton *button,Widgets *w);
void day_text(GtkButton *button,Widgets *w);
void button_am (GtkButton *button,Widgets *w);
void button_pm (GtkButton *button,Widgets *w);
void window_setting();
void day_set();
void time_set();
void close_set();


void city_set()
{
	Widgets *w_city = g_slice_new (Widgets);
	vbox = gtk_vbox_new (FALSE, 5);//creat box
	/*create "city" label*/
	label = gtk_label_new("도시");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*first insert button*/
	insert = gtk_button_new_with_label ("Insert Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (city_text),(gpointer) w_city);
	/*text*/
	w_city->textview = gtk_text_view_new ();
	w_city->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win),w_city->textview);
	/*create hbox*/
	hbox_city= gtk_hbox_new (FALSE, 5);
	gtk_box_pack_start_defaults (GTK_BOX (hbox_city),w_city->entry);//put write place to hbox 
	gtk_box_pack_start_defaults (GTK_BOX (hbox_city), insert);//put inset button to hbox
	/*put to vbox*/ 
	gtk_box_pack_start (GTK_BOX (vbox), hbox_city, FALSE, TRUE, 0);//put hbox to vbox
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);//put text window to vbox
}
/*if click first insert button after write city name, print "you write this cityname"*/
void city_text (GtkButton *button,Widgets *w)
{

	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));
	city=text;//store city name to global variable
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" 입력하셨습니다";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
}

/*if click second insert button after write day, print "you write day"*/
void day_text(GtkButton *button,Widgets *w)
{
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;

	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));

	day=text;//store day to global variable
	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	gtk_text_buffer_insert (buffer, &iter, text, -1);
	text=" 입력하셨습니다";
	gtk_text_buffer_insert (buffer, &iter, text, -1);
//	printf("Entry contents: %s\n", what);
//	printf("Entry contents: %s\n", text);
}

/*if click am button, button_am function run*/
void button_am (GtkButton *button,Widgets *w)
{

	int i;
	int flag;
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	changeseoul();
	changekangwon();
	changechungcheong();
	changejeonla();
	changegyeongsang();
	changejeju();
	/*i don know exactly*/
	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));

	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	/*print to textwindow  */
	printf("city: %s\n", city);
	printf("day: %s\n", day);
	//printf("compare : %s \n",compare);
	for(i=0;i<5;i++)
	{
		if(!(strcmp(seoul[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=0;
		}
	}
	for(i=0;i<4;i++)
	{
		if(!(strcmp(kangwon[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=1;
		}
	}
	for(i=0;i<5;i++)
	{
		if(!(strcmp(chungcheong[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=2;
		}
	}
	for(i=0;i<6;i++)
	{
		if(!(strcmp(jeonla[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=3;
		}
	}
	for(i=0;i<7;i++)
	{
		if(!(strcmp(gyeongsang[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=4;
		}
	}
	for(i=0;i<3;i++)
	{
		if(!(strcmp(jeju[i][1][0].name,city)))
		{
			a_am=i;
		//	printf("a=%d\n",a);
			flag=5;
		}
	}		
	if(!(strcmp(day,"2")))
	{
		b_am=1;
		c_am=0;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"3")))
	{
		b_am=1;
		c_am=2;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"4")))
	{
		b_am=1;
		c_am=4;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"5")))
	{
		b_am=1;
		c_am=6;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"6")))
	{
		b_am=1;
		c_am=8;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"7")))
	{
		b_am=0;
		c_am=0;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"8")))
	{
		b_am=0;
		c_am=1;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"9")))
	{
		b_am=0;
		c_am=2;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(flag==0)
	{
		text=seoul[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==1)
	{
		text=kangwon[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==2)
	{
		text=chungcheong[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==3)
	{
		text=jeonla[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==4)
	{
		text=gyeongsang[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==5)
	{
		text=jeju[a_am][b_am][c_am].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_am][b_am][c_am].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_am][b_am][c_am].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_am][b_am][c_am].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_am][b_am][c_am].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	//printf("Entry contents: %s\n", seoul[0][1][6].date);
	//printf("Entry contents: %s\n", seoul[a][b][c].date);

	//printf("Entry contents: %s\n", w->text_out);
	//printf("Entry contents: %s\n", text);
}

/*if click pm button, button_pm function run*/
void button_pm (GtkButton *button,Widgets *w)
{

	int i;
	int flag;
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const gchar *text;
	changeseoul();
	changekangwon();
	changechungcheong();
	changejeonla();
	changegyeongsang();
	changejeju();
	/*i don know exactly*/
	buffer = gtk_text_view_get_buffer
	(GTK_TEXT_VIEW (w->textview));
	text = gtk_entry_get_text (GTK_ENTRY (w->entry));

	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_get_iter_at_mark (buffer, &iter, mark);
	/*print to textwindow  */
	printf("city: %s\n", city);
	printf("day: %s\n", day);
	//printf("compare : %s \n",compare);
	for(i=0;i<5;i++)
	{
		if(!(strcmp(seoul[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=0;
		}
	}
	for(i=0;i<4;i++)
	{
		if(!(strcmp(kangwon[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=1;
		}
	}
	for(i=0;i<5;i++)
	{
		if(!(strcmp(chungcheong[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=2;
		}
	}
	for(i=0;i<6;i++)
	{
		if(!(strcmp(jeonla[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=3;
		}
	}
	for(i=0;i<7;i++)
	{
		if(!(strcmp(gyeongsang[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=4;
		}
	}
	for(i=0;i<3;i++)
	{
		if(!(strcmp(jeju[i][1][0].name,city)))
		{
			a_pm=i;
	//		printf("a=%d\n",a);
			flag=5;
		}
	}		
	if(!(strcmp(day,"2")))
	{
		b_pm=1;
		c_pm=1;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"3")))
	{
		b_pm=1;
		c_pm=3;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"4")))
	{
		b_pm=1;
		c_pm=5;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"5")))
	{
		b_pm=1;
		c_pm=7;
	///	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"6")))
	{
		b_pm=1;
		c_pm=9;
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"7")))
	{
		b_pm=0;
		c_pm=0;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"8")))
	{
		b_pm=0;
		c_pm=1;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(!(strcmp(day,"9")))
	{
		b_pm=0;
		c_pm=2;
		text="하루날씨";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	//	printf("b,c%d,%d\n",b,c);
	}
	if(flag==0)
	{
		text=seoul[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=seoul[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==1)
	{
		text=kangwon[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=kangwon[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==2)
	{
		text=chungcheong[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=chungcheong[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==3)
	{
		text=jeonla[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeonla[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==4)
	{
		text=gyeongsang[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=gyeongsang[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
	else if(flag==5)
	{
		text=jeju[a_pm][b_pm][c_pm].name;

		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_pm][b_pm][c_pm].date;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_pm][b_pm][c_pm].time;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_pm][b_pm][c_pm].weather;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=" ";
		gtk_text_buffer_insert (buffer, &iter, text, -1);
		text=jeju[a_pm][b_pm][c_pm].condition;
		gtk_text_buffer_insert (buffer, &iter, text, -1);
	}
}

void window_setting()
{
	/*create window*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "오늘 날씨 어때?");
	gtk_signal_connect(GTK_OBJECT (window), "delete_event",(GtkSignalFunc) gtk_exit, NULL);//if click x button,exit 
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_widget_set_usize( GTK_WIDGET (window), 400, 400);//window size
}

void day_set()
{
	Widgets *w_day = g_slice_new (Widgets);
	/*create "day" label*/
	label = gtk_label_new("몇일후");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/*second insert button*/
	insert = gtk_button_new_with_label ("Insert Text");
	g_signal_connect (G_OBJECT (insert), "clicked",G_CALLBACK (day_text),(gpointer) w_day);
	/*text*/
	w_day->textview = gtk_text_view_new ();
	w_day->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w_day->textview);
	/*create hbox*/
	hbox_day= gtk_hbox_new (FALSE, 5);	
	gtk_box_pack_start_defaults (GTK_BOX (hbox_day), w_day->entry);
	gtk_box_pack_start_defaults (GTK_BOX (hbox_day), insert);
	/*put to vbox*/
	gtk_box_pack_start (GTK_BOX (vbox), hbox_day, FALSE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);
}
void time_set()
{
	Widgets *w_weather = g_slice_new (Widgets);
	/*am pm*/
	hbox_time = gtk_hbox_new (FALSE, 5);	
	/*am button*/
	button = gtk_button_new_with_label ("am");
	g_signal_connect(GTK_OBJECT (button), "clicked",G_CALLBACK(button_am),(gpointer) w_weather);
	gtk_box_pack_start (GTK_BOX (hbox_time), button, TRUE, TRUE, 0);//hbox에 첨가 
	/*pm button*/
	button = gtk_button_new_with_label ("pm");
	g_signal_connect (GTK_OBJECT (button), "clicked",G_CALLBACK(button_pm),(gpointer) w_weather);
	gtk_box_pack_start (GTK_BOX (hbox_time), button, TRUE, TRUE, 0);//hbox에 첨가
	gtk_container_add (GTK_CONTAINER (vbox), hbox_time); 
	/*weather_text*/
	w_weather->textview = gtk_text_view_new ();
	w_weather->entry = gtk_entry_new ();
	scrolled_win = gtk_scrolled_window_new (NULL, NULL);
	gtk_container_add (GTK_CONTAINER (scrolled_win), w_weather->textview);
	/*put to vbox*/
	gtk_box_pack_start (GTK_BOX (vbox), scrolled_win, TRUE, TRUE, 0);
}
void close_set()
{
	/*close*/
	button = gtk_button_new_with_label ("Close");
	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",GTK_SIGNAL_FUNC(gtk_exit),GTK_OBJECT (window));
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);
	/*end*/    
	gtk_container_add (GTK_CONTAINER (window), vbox);
	gtk_widget_show_all (window);

	gtk_main();
}
int main (int argc,char *argv[])
{


	gtk_init (&argc, &argv);
	window_setting();
	city_set();
	day_set();
	time_set();
	close_set();



    return 0;
}

