#include <stdio.h>
#include "change.h"

//struct city seoul[4][2][10];

int main()
{
	int i;
	int k=0;
	changeseoul();
//	changekangwon();
/*	for(k=0; k<4; k++)
	{
		printf("-----------A2시작-----------\n");
		for(i=0; i<10; i++)
		{
			printf("%s	\n",seoul[k][1][i].date);	
			printf("%s	\n",seoul[k][1][i].time);
			printf("%s	\n",seoul[k][1][i].weather);
			printf("%d	\n",seoul[k][1][i].temp);
			printf("%d	\n",seoul[k][1][i].temp_max);
			printf("%s	\n",seoul[k][1][i].condition);
			printf("\n");
		}
	
		printf("-----------A1시작-----------\n");
		for(i=0; i<3; i++)
		{
			printf("%s	\n",seoul[k][0][i].date);	
			printf("%s	\n",seoul[k][0][i].time);
			printf("%s	\n",seoul[k][0][i].weather);
			printf("%d	\n",seoul[k][0][i].temp);
			printf("%d	\n",seoul[k][0][i].temp_max);
			printf("%s	\n",seoul[k][0][i].condition);
			printf("\n");
		}
	}
*/

	changekangwon();	

	for(k=0; k<3; k++)
	{
		printf("-----------A2시작-----------\n");
		for(i=0; i<10; i++)
		{
			printf("%s	\n",kangwon[k][1][i].date);	
			printf("%s	\n",kangwon[k][1][i].time);
			printf("%s	\n",kangwon[k][1][i].weather);
			printf("%d	\n",kangwon[k][1][i].temp);
			printf("%d	\n",kangwon[k][1][i].temp_max);
			printf("%s	\n",kangwon[k][1][i].condition);
			printf("\n");
		}
	
		printf("-----------A1시작-----------\n");
		for(i=0; i<3; i++)
		{
			printf("%s	\n",kangwon[k][0][i].date);	
			printf("%s	\n",kangwon[k][0][i].time);
			printf("%s	\n",kangwon[k][0][i].weather);
			printf("%d	\n",kangwon[k][0][i].temp);
			printf("%d	\n",kangwon[k][0][i].temp_max);
			printf("%s	\n",kangwon[k][0][i].condition);
			printf("\n");
		}
	}

	return 0;
}
