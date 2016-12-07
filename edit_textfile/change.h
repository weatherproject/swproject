extern struct city{
	char date[30];
	char time[10];
	char weather[18];
	int temp;
	int temp_max;
	char condition[10];
};


extern struct city seoul[4][2][10];
extern struct city kangwon[4][2][10];
extern struct city chungcheong[4][2][10];


int changeseoul();
int changekangwon();
int changechungcheong();




