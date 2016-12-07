dir = ~/Desktop/weather/swproject/main
library = /home/jooyeon/Desktop/weather/swproject/edit_textfile



main : 
	@cp $(library)/weather_text.txt $(dir); \
	gcc -o main main.c -L$(library) -lfuncs -I$(library) 

clean:
	rm $(dir)/main
