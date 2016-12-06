#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city{
	char date[30];
	char time[10];
	char weather[15];
	int temp;
	int temp_max;
	char condition[10];
};


int main()
{
	//char *c=0;
	char str[500]={0,};
	struct city A02[10]={0,};
	struct city A01[10]={0,};
	char city_name[300];
	char city_main[100];
	int i=0;

	
	FILE *fp = fopen("weather_text.txt","rt");

	if(fp == NULL)
	{
		printf("실패");
		return 0;
	}

	 
	while(1)
	{
		
		fgets(str,500,fp);
		//fscanf(fp,"%s \n",&str);
		printf("%s\n",str);

		//strcpy(str,"");
		
		
		i++;
		if(i>5)
			break;
	}
	

	while(feof(fp) ==0)
	{
		if(strstr(city_name,"서울ㆍ인천ㆍ경기도"))
		{
			fscanf(fp,"%s \n",&str);
			strcpy(city_main,str);
			if(strstr(city_main,"서울"))
			{
				fscanf(fp,"%s \n",&str);
				for(i=0; i<10; i++)
				{
					if(strstr(str,"A02"))									//중기날씨 5일
					{
						fscanf(fp,"%s \n",&A02[i].date);
						fscanf(fp,"%s \n",&A02[i].time);
						fgets(A02[i].weather,10,fp);
						//fscanf(fp,"%s \n",&A02[i].weather);
						fscanf(fp,"%d \n",&A02[i].temp);
						fscanf(fp,"%d \n",&A02[i].temp_max);
						fscanf(fp,"%s \n",&A02[i].condition);
					}
					fscanf(fp,"%s \n",&str);
				}
				for(i=0; i<3; i++)
				{
					if(strstr(str,"A01"))
					{
						fscanf(fp,"%s \n",&A01[i].date);
						fscanf(fp,"%s \n",&A01[i].time);
						fgets(A01[i].weather,10,fp);
						//fscanf(fp,"%s \n",&A02[i].weather);
						fscanf(fp,"%d \n",&A01[i].temp);
						fscanf(fp,"%d \n",&A01[i].temp_max);
						fscanf(fp,"%s \n",&A01[i].condition);
					}
					fscanf(fp,"%s \n",&str);
				}
						
			}
		}
	}
	
	fclose(fp);
	for(i=0; i<10; i++)
	{
		printf("%s	\n",A02[i].date);	
		printf("%s	\n",A02[i].time);
		printf("%s	\n",A02[i].weather);
		printf("%d	\n",A02[i].temp);
		printf("%d	\n",A02[i].temp_max);
		printf("%s	\n",A02[i].condition);
		printf("\n");
	}
	printf("-----------A1시작-----------\n");
	for(i=0; i<3; i++)
	{
		printf("%s	\n",A01[i].date);	
		printf("%s	\n",A01[i].time);
		printf("%s	\n",A01[i].weather);
		printf("%d	\n",A01[i].temp);
		printf("%d	\n",A01[i].temp_max);
		printf("%s	\n",A01[i].condition);
		printf("\n");
	}
	return 0;

}
