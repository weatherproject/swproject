gtk = `pkg-config --libs --cflags gtk+-2.0`
dir = /home/jooyeon/Desktop/weather/swproject/WEATHER_GUI/include
libhed = /home/jooyeon/Desktop/weather/swproject/edit_textfile

main : main.c
	gcc -g -Wall main.c -o main -L../lib -lfuncs -I$(libhed) -I$(dir) $(gtk)

clean:
	rm main
