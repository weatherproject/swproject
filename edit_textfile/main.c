#include <stdio.h>
#include "seoulgyeonggi.h"

//struct city seoul[4][2][10];

void main()
{
	int i;
	int k=0;
	changeseoul();

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
