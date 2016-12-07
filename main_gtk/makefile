DIR = ~/Desktop/weather/swproject/main_gtk
gtk = `pkg-config --cflags --libs gtk+-2.0`
library = /home/jooyeon/Desktop/weather/swproject/edit_textfile
filedir = /home/jooyeon/Desktop/weather/swproject/weather_textfile

final :
	@cp $(filedir)/weather_text.txt $(DIR); \
	gcc -o what  what.c -L$(library) -lfuncs -I$(library) $(gtk)

clean:
	rm weather_text.txt what 
