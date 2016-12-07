Rc = RandomCard
Wi = function
gtk = `pkg-config --libs --cflags gtk+-2.0`
dir = /home/seojin/swproject/WEATHER_GTK/include
lib = libfuncs.a
gw = -g -Wall
$(lib) : $(Wi).o
	ar rv $(lib) $(Wi).o

$(Wi).o : $(Wi).c 
	gcc -g -Wall -c $(Wi).c  -I$(dir) $(gtk)

clean:
	rm *.o libfuncs.a
