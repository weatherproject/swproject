#include <gtk/gtk.h>

GtkWidget *hscale, *vscale;

void cb_pos_menu_select( GtkWidget *item,GtkPositionType  pos )
{
   // Set the value position on both scale widgets 
    gtk_scale_set_value_pos (GTK_SCALE (hscale), pos);
    gtk_scale_set_value_pos (GTK_SCALE (vscale), pos);
}

void cb_update_menu_select( GtkWidget *item, GtkUpdateType  policy )
{
   //  Set the update policy for both scale widgets 
    gtk_range_set_update_policy (GTK_RANGE (hscale), policy);
    gtk_range_set_update_policy (GTK_RANGE (vscale), policy);
}


/* Convenience functions */

GtkWidget *make_menu_item (gchar *name, GCallback callback, gpointer data)
{
	GtkWidget *item;
  
	item = gtk_menu_item_new_with_label (name);
	g_signal_connect (G_OBJECT (item), "activate",callback, (gpointer) data);
	gtk_widget_show (item);

	return item;
}


/* makes the sample window */

void create_range_controls( void )
{
	GtkWidget *window;
	GtkWidget *box1;
	GtkWidget *opt, *menu, *item;

	/* Standard window-creating stuff */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);//윈도우 만들기 
	g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (gtk_main_quit),NULL);//창끄는거 
	gtk_window_set_title (GTK_WINDOW (window), "range controls");//제목 

	box1 = gtk_vbox_new (FALSE, 0);// box1만들기 
	gtk_container_set_border_width (GTK_CONTAINER (box1), 10);//박스1 크기 
	gtk_container_add (GTK_CONTAINER (window), box1);//윈도우에 박스1 포함 
	gtk_widget_show (box1);//박스 1 보이게 
	
	/*옵션만들기*/
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
	gtk_box_pack_start (GTK_BOX (box1), opt, TRUE, TRUE, 0);//박스1에 옵션 넣음 
	gtk_widget_show (opt);//옵션 보여줘 


//
/*
    opt = gtk_option_menu_new ();
    menu = gtk_menu_new ();
  
    item = make_menu_item ("Continuous",
                           G_CALLBACK (cb_update_menu_select),
                           GINT_TO_POINTER (GTK_UPDATE_CONTINUOUS));
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    item = make_menu_item ("Discontinuous",
                           G_CALLBACK (cb_update_menu_select),
                           GINT_TO_POINTER (GTK_UPDATE_DISCONTINUOUS));
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    item = make_menu_item ("Delayed",
                           G_CALLBACK (cb_update_menu_select),
                           GINT_TO_POINTER (GTK_UPDATE_DELAYED));
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
  
    gtk_option_menu_set_menu (GTK_OPTION_MENU (opt), menu);
    gtk_box_pack_start (GTK_BOX (box2), opt, TRUE, TRUE, 0);
    gtk_widget_show (opt);
  
    gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    gtk_widget_show (box2);

    box2 = gtk_hbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
 */ 
//
	gtk_widget_show (window);
}

int main( int argc,char *argv[] )
{
	gtk_init (&argc, &argv);

	create_range_controls ();

	gtk_main ();

	return 0;
}

