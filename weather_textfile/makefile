dir = /home/jooyeon/Desktop/weather/swproject/weather_textfile

output : weather_test weather_file
	./weather_test weather_file | tee weather_text.txt

weather_test : weather_text.c
	gcc -o weather_test weather_text.c -I/usr/include/libxml2 -L/usr/lib/i386-linux-gnu -lxml2

weather_file :
	wget -O weather_file http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=108

clean:
	rm *.txt weather_file
