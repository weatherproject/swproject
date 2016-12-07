Rc = RandomCard
Wi = function
gtk = `pkg-config --libs --cflags gtk+-2.0`
dir = ~/Desktop/weather/swproject/WEATHER_GTK/include
libhed = /home/jooyeon/Desktop/weather/swproject/edit_textfile
lib = libfuncs.a
gw = -g -Wall


$(lib) : $(Wi).o
	ar rv $(lib) $(Wi).o

$(Wi).o : $(Wi).c 
	gcc -g -Wall -c $(Wi).c -L$(libhed) -lfuncs -I$(libhed) -I$(dir) $(gtk) 

clean:
	rm *.o libfuncs.a
