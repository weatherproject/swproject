objects = seoul.o gyeongsang.o jeonla.o chungcheong.o jeju.o kangwon.o
com = -fPIC
dir = ~/Desktop/weather/swproject/edit_textfile
filedir = ~/Desktop/weather/swproject/weather_textfile
library = libfuncs.a
.PHONY: clean



$(library): $(objects)
	ar rv $(library) $(objects)

%.o: %.c
	@cp $(filedir)/weather_text.txt $(dir); \
	gcc -g -Wall -c $^ -o $@

clean:
	rm $(dir)/*.o weather_text.txt libfuncs.a
