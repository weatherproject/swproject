dir = ~/Desktop/weather/swproject/main
library = /home/jooyeon/Desktop/weather/swproject/edit_textfile
filedir = /home/jooyeon/Desktop/weather/swproject/weather_textfile

main : 
	@cp $(filedir)/weather_text.txt $(dir); \
	gcc -o main main.c -L$(library) -lfuncs -I$(library) 

clean:
	rm $(dir)/main
