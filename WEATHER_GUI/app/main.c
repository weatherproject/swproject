#include "Header.h"
#include <gtk/gtk.h>

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

