
#include <stdio.h>
#include <gtk/gtk.h>

void enter_callback( GtkWidget *widget,GtkWidget *entry )
{
  gchar *entry_text;
  entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
  printf("Entry contents: %s\n", entry_text);
}

void entry_toggle_editable( GtkWidget *checkbutton,GtkWidget *entry )
{
/*
  gtk_entry_set_editable(GTK_ENTRY(entry),
                         GTK_TOGGLE_BUTTON(checkbutton)->active);
*/
}

void entry_toggle_visibility( GtkWidget *checkbutton,GtkWidget *entry )
{
/*
  gtk_entry_set_visibility(GTK_ENTRY(entry),
                         GTK_TOGGLE_BUTTON(checkbutton)->active);
*/
}

int main( int   argc,char *argv[] )
{

	GtkWidget *window;
	GtkWidget *vbox, *hbox;
   	GtkWidget *entry;
    	GtkWidget *button;
	GtkWidget *check;
	GtkWidget *label;
	gtk_init (&argc, &argv);

	/* create a new window */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//window가 바탕임 
	gtk_widget_set_usize( GTK_WIDGET (window), 300, 200);//크기 
	gtk_window_set_title(GTK_WINDOW (window), "HOW'S THE WEATHER TODAY?");//제목 
	gtk_signal_connect(GTK_OBJECT (window), "delete_event",(GtkSignalFunc) gtk_exit, NULL);//엑스 눌렀을때 나가라 
	vbox = gtk_vbox_new (FALSE, 0);//vbox쓰겠다 
	gtk_container_add (GTK_CONTAINER (window), vbox);//window에 vbox넣겠다 
	gtk_widget_show (vbox);//vbox보여줘 
	/*"city" label*/
	label = gtk_label_new("도시");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label);
	/* creat "city" enrtry*/ 
	entry = gtk_entry_new_with_max_length (50);//entry가 텍스트 상자 
	gtk_signal_connect(GTK_OBJECT(entry), "activate",GTK_SIGNAL_FUNC(enter_callback),entry);//entry가 enter_callback함수 쓰도록 
	//gtk_entry_set_text (GTK_ENTRY (entry), "hello");//entry에 hello를 넣자 
	//gtk_entry_append_text (GTK_ENTRY (entry), " world");//entry에 world를 붙여 넣자 
	gtk_entry_select_region (GTK_ENTRY (entry),0, GTK_ENTRY(entry)->text_length);//?
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);//vbox에 entry를 pack
	gtk_widget_show (entry);
	/*"day" label*/
	label = gtk_label_new("몇일후");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label); 
	/* creat "day" entry*/
	entry = gtk_entry_new_with_max_length (50);//entry가 텍스트 상자 
	gtk_signal_connect(GTK_OBJECT(entry), "activate",
	GTK_SIGNAL_FUNC(enter_callback),entry);//entry가 enter_callback함수 쓰도록 
	gtk_entry_select_region (GTK_ENTRY (entry),0, GTK_ENTRY(entry)->text_length);//?
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);//vbox에 entry를 pack
	gtk_widget_show (entry);
	//
	/*creat hbox*/
	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (vbox), hbox);
	gtk_widget_show (hbox);
	/*am checkbox*/
	check = gtk_check_button_new_with_label("오전");//editable라벨 붙은  check button
	gtk_box_pack_start (GTK_BOX (hbox), check, TRUE, TRUE, 0);//hbox에 첨가 
	gtk_signal_connect (GTK_OBJECT(check), "toggled",GTK_SIGNAL_FUNC(entry_toggle_editable), entry);//check이벤트 
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), TRUE);
	gtk_widget_show (check);
	/*pm checkbox*/
	check = gtk_check_button_new_with_label("오후");
	gtk_box_pack_start (GTK_BOX (hbox), check, TRUE, TRUE, 0);
	gtk_signal_connect (GTK_OBJECT(check), "toggled",
	GTK_SIGNAL_FUNC(entry_toggle_visibility), entry);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check), TRUE);
	gtk_widget_show (check);
	/*"weather" label*/
	label = gtk_label_new("날씨");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label); 
	/*creat weather box*/
	entry = gtk_entry_new_with_max_length (50);//entry가 텍스트 상자 
	gtk_signal_connect(GTK_OBJECT(entry), "activate",
	GTK_SIGNAL_FUNC(enter_callback),entry);//entry가 enter_callback함수 쓰도록 
	gtk_entry_select_region (GTK_ENTRY (entry),0, GTK_ENTRY(entry)->text_length);//?
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);//vbox에 entry를 pack
	gtk_widget_show (entry);	
	/*close button*/            
	button = gtk_button_new_with_label ("Close");
	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",GTK_SIGNAL_FUNC(gtk_exit),GTK_OBJECT (window));
	gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (button);
	gtk_widget_show (button);
	/*window come on*/    
	gtk_widget_show(window);
	/*end*/
	gtk_main();
	return(0);
}

