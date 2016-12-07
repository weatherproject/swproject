gtk = `pkg-config --libs --cflags gtk+-2.0`
dir = /home/seojin/swproject/WEATHER_GTK

main : main.c
	gcc -g -Wall main.c -o main -L../lib -lfuncs -I../include $(gtk)

clean:
	rm main
