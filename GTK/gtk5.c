
#include <stdio.h>
#include <gtk/gtk.h>

//about option
GtkWidget *hscale, *vscale;

void cb_pos_menu_select(GtkWidget *item,GtkPositionType  pos )
{
   // Set the value position on both scale widgets 
   // gtk_scale_set_value_pos (GTK_SCALE (hscale), pos);
   //gtk_scale_set_value_pos (GTK_SCALE (vscale), pos);
	//gtk_entry_set_text (GTK_ENTRY (entry), data);
	//gtk_signal_connect(GTK_OBJECT(entry), "activate",GTK_SIGNAL_FUNC(enter_callback),entry);
printf("Entry contents: %s\n", "클릭");
}

void cb_update_menu_select( GtkWidget *item, GtkUpdateType  policy )
{
   //  Set the update policy for both scale widgets 
    gtk_range_set_update_policy (GTK_RANGE (hscale), policy);
    gtk_range_set_update_policy (GTK_RANGE (vscale), policy);
}
// Convenience functions 

GtkWidget *make_menu_item (gchar *name, GCallback callback, gpointer data)
{
	GtkWidget *item;
  
	item = gtk_menu_item_new_with_label (name);
	g_signal_connect (G_OBJECT (item), "activate",callback, (gpointer) data);
	//printf("Entry contents: %s\n", name);
	gtk_widget_show (item);

	return item;
}

//

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
	GtkWidget *opt, *menu, *item;
	gtk_init (&argc, &argv);

	/* create a new window */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//window가 바탕임 
	gtk_widget_set_usize( GTK_WIDGET (window), 400, 300);//크기 
	gtk_window_set_title(GTK_WINDOW (window), "HOW'S THE WEATHER TODAY?");//제목 
	gtk_signal_connect(GTK_OBJECT (window), "delete_event",(GtkSignalFunc) gtk_exit, NULL);//엑스 눌렀을때 나가라 
	vbox = gtk_vbox_new (FALSE, 0);//vbox쓰겠다 
	gtk_container_add (GTK_CONTAINER (window), vbox);//window에 vbox넣겠다 
	gtk_widget_show (vbox);//vbox보여줘
	/*"city" label*/
	label = gtk_label_new("도시");
	gtk_box_pack_start(GTK_BOX(vbox),label,1,1,0);
	gtk_widget_show(label); 
	/*option bix*/

	opt = gtk_option_menu_new ();//옵션 만들기 
	menu = gtk_menu_new ();//메뉴만들기 

	item = make_menu_item ("서울",G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_TOP));//분석필요 
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);//위에서 만든걸 메뉴에 포함 
  
	item = make_menu_item ("인천", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_BOTTOM));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	item = make_menu_item ("김포", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_LEFT));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	item = make_menu_item ("강원", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_RIGHT));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	gtk_option_menu_set_menu (GTK_OPTION_MENU (opt), menu);//메뉴를 옵션에 설정
	gtk_box_pack_start (GTK_BOX (vbox), opt, TRUE, TRUE, 0);//박스1에 옵션 넣음 
	gtk_widget_show (opt);//옵션 보여줘 

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
	/*option bix*/

	opt = gtk_option_menu_new ();//옵션 만들기 
	menu = gtk_menu_new ();//메뉴만들기 

	item = make_menu_item ("1일후",G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_TOP));//분석필요 
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);//위에서 만든걸 메뉴에 포함 
  
	item = make_menu_item ("2일후", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_BOTTOM));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	item = make_menu_item ("3일후", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_LEFT));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	item = make_menu_item ("4일후", G_CALLBACK (cb_pos_menu_select),GINT_TO_POINTER (GTK_POS_RIGHT));
	gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
	gtk_option_menu_set_menu (GTK_OPTION_MENU (opt), menu);//메뉴를 옵션에 설정
	gtk_box_pack_start (GTK_BOX (vbox), opt, TRUE, TRUE, 0);//박스1에 옵션 넣음 
	gtk_widget_show (opt);//옵션 보여줘
	/* creat "day" entry*/
	entry = gtk_entry_new_with_max_length (50);//entry가 텍스트 상자 
	gtk_signal_connect(GTK_OBJECT(entry), "activate",
	GTK_SIGNAL_FUNC(enter_callback),entry);//entry가 enter_callback함수 쓰도록 
	gtk_entry_select_region (GTK_ENTRY (entry),0, GTK_ENTRY(entry)->text_length);//?
	gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);//vbox에 entry를 pack
	gtk_widget_show (entry);
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


