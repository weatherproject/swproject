objects = seoul.o gyeongsang.o jeonla.o chungcheong.o jeju.o kangwon.o
com = -fPIC
dir = ~/Desktop/weather/swproject/edit_textfile
library = libfuncs.a
.PHONY: clean

$(library): $(objects)
	ar rv $(library) $(objects)

%.o: %.c
	gcc -g -Wall -c $^ -o $@

clean:
	rm $(dir)/*.o
