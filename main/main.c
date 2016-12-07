#nclude "../edit_textfile/seoulgyeonggi.h"

void main()
{
	int k,i;

	for(k=0; k<4; k++)
	{
		printf("%s 	\n",city_save_name[k]);
		
		printf("-----------A2시작-----------\n");
		for(i=0; i<10; i++)
		{
			printf("%s	\n",citys[k][1][i].date);	
			printf("%s	\n",citys[k][1][i].time);
			printf("%s	\n",citys[k][1][i].weather);
			printf("%d	\n",citys[k][1][i].temp);
			printf("%d	\n",citys[k][1][i].temp_max);
			printf("%s	\n",citys[k][1][i].condition);
			printf("\n");
		}
		printf("-----------A1시작-----------\n");
		for(i=0; i<3; i++)
		{
			printf("%s	\n",citys[k][0][i].date);	
			printf("%s	\n",citys[k][0][i].time);
			printf("%s	\n",citys[k][0][i].weather);
			printf("%d	\n",citys[k][0][i].temp);
			printf("%d	\n",citys[k][0][i].temp_max);
			printf("%s	\n",citys[k][0][i].condition);
			printf("\n");
		}

		printf("\n\n");
	}
}
