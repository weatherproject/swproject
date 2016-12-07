#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"

struct city jeju[4][2][10]={0,};

int changejeju()
{
	char str[500]={0,};
	char city_name[300];
	char city_main[200]={'0',};
	char city_save_name[6][100]={0,};
	int i=0;
	int k=0;
	int flag=0;	

	FILE *fp = fopen("weather_text.txt","rt");

	if(fp == NULL)
	{
		printf("실패");
		return 0;
	}


	while(1)
	{

		//fgets(str,500,fp);
		fscanf(fp,"%s \n",&str);
		//printf("%s\n",str);

		//strcpy(str,"");
		if(strstr(str,"제주도"))
		{
			//flag=1;
			flag=0;
			strcpy(city_name,str);
			//printf("%s	\n",str);
			printf("%s	\n",city_name);
			break;
		}
	}
	
	
	while(feof(fp) ==0)
	{
		if(strstr(city_name,"제주도"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"제주"))
				{	
					printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&jeju[flag][1][i].date);
							fscanf(fp,"%s \n",&jeju[flag][1][i].time);
							fgets(jeju[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&jeju[flag][1][i].temp);
							fscanf(fp,"%d \n",&jeju[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&jeju[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&jeju[flag][0][i].date);
							fscanf(fp,"%s \n",&jeju[flag][0][i].time);
							fgets(jeju[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&jeju[flag][0][i].temp);
							fscanf(fp,"%d \n",&jeju[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&jeju[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =1;
					//break;
				}		
			}
			else if(flag==1)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"서귀포"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&jeju[flag][1][i].date);
							fscanf(fp,"%s \n",&jeju[flag][1][i].time);
							fgets(jeju[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&jeju[flag][1][i].temp);
							fscanf(fp,"%d \n",&jeju[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&jeju[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&jeju[flag][0][i].date);
							fscanf(fp,"%s \n",&jeju[flag][0][i].time);
							fgets(jeju[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&jeju[flag][0][i].temp);
							fscanf(fp,"%d \n",&jeju[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&jeju[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					break;
				}		
			}
		}
			
	}

	

	fclose(fp);

	return 0;

}
