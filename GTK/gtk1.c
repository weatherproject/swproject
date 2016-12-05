#include <gtk/gtk.h>

GtkWidget *label;

void button_clicked ( GtkWidget *widget, gpointer data)  
{  
	static int toggle = 1;  
	if (toggle == 1)  
	{  
		gtk_label_set_text ( GTK_LABEL(label) , "hello world opened");  
		toggle = 0;  
	}  
	else  
	{  
		gtk_label_set_text ( GTK_LABEL(label) , "hello world closed");  
		toggle = 1;  
	}  
}

void delete_event ( GtkWidget *widget, GdkEvent *event, gpointer data) 
{
	gtk_main_quit();
}

int main(int argc,char *argv[])
{
	GtkWidget *window;

	GtkWidget *button;
	GtkWidget *vbox;
	gtk_init(&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW (window),"upgrade hello world");
	gtk_signal_connect (GTK_OBJECT (window),"delete_event",GTK_SIGNAL_FUNC (delete_event),NULL);

	gtk_container_border_width (GTK_CONTAINER (window), 30);
	vbox=gtk_vbox_new(0, 0);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	label = gtk_label_new("hello world closed");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	button =gtk_button_new_with_label("click");
	gtk_signal_connect (GTK_OBJECT (button),"clicked",GTK_SIGNAL_FUNC (button_clicked),NULL);
	gtk_box_pack_start(GTK_BOX(vbox),button,1,1,0);
	gtk_widget_show(button);
	gtk_widget_show(vbox);		

	gtk_widget_show(window);
	gtk_main();
	return 0;
}



