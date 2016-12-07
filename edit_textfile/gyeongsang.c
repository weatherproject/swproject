#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "change.h"

struct city{
	char date[30];
	char time[10];
	char weather[18];
	int temp;
	int temp_max;
	char condition[10];
};



struct city jeonla[4][2][10]={0,};



int main ()
{
	char str[500]={0,};
	char city_name[300];
	char city_main[100]={0,};
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
		fscanf(fp,"%s \n",&str);

		if(strstr(str,"전라북도"))
		{
			flag=0;
			strcpy(city_name,str);
			break;
		}
	}
	
	
	while(feof(fp) ==0)
	{
		if(strstr(city_name,"전라북도"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"전주"))
				{	
					printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&jeonla[flag][1][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].time);
							fgets(jeonla[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&jeonla[flag][0][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].time);
							fgets(jeonla[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =1;
				}		
			}
			else if(flag==1)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"군산"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&jeonla[flag][1][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].time);
							fgets(jeonla[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&jeonla[flag][0][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].time);
							fgets(jeonla[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =2;
				}		
			}
			
		}
		if(strstr(city_name,"광주ㆍ전라남도"))
		{
			
			if(flag==2)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"광주"))
				{	
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&jeonla[flag][1][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].time);
							fgets(jeonla[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&jeonla[flag][0][i].date);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].time);
							fgets(jeonla[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp);
							fscanf(fp,"%d \n",&jeonla[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&jeonla[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag=3;
				}		
			}
			else if(flag==3)
			{
					fscanf(fp,"%s \n",&str);
					strcpy(city_main,str);
					if(!strcmp(str,"목포"))
					{	
						//printf("%s \n",str);
						strcpy(city_save_name[flag],city_main);
						fscanf(fp,"%s \n",&str);
						for(i=0; i<10; i++)
						{
							if(strstr(str,"A02"))									//중기날씨 5일
							{
								fscanf(fp,"%s \n",&jeonla[flag][1][i].date);
								fscanf(fp,"%s \n",&jeonla[flag][1][i].time);
								fgets(jeonla[flag][1][i].weather,15,fp);
								fscanf(fp,"%d \n",&jeonla[flag][1][i].temp);
								fscanf(fp,"%d \n",&jeonla[flag][1][i].temp_max);
								fscanf(fp,"%s \n",&jeonla[flag][1][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						for(i=0; i<3; i++)
						{
							if(strstr(str,"A01"))
							{
								fscanf(fp,"%s \n",&jeonla[flag][0][i].date);
								fscanf(fp,"%s \n",&jeonla[flag][0][i].time);
								fgets(jeonla[flag][0][i].weather,15,fp);
								fscanf(fp,"%d \n",&jeonla[flag][0][i].temp);
								fscanf(fp,"%d \n",&jeonla[flag][0][i].temp_max);
								fscanf(fp,"%s \n",&jeonla[flag][0][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						flag=4;
					}		
			
			}
			else if(flag==4)
			{
					fscanf(fp,"%s \n",&str);
					strcpy(city_main,str);
					if(!strcmp(str,"여수"))
					{	
						//printf("%s \n",str);
						strcpy(city_save_name[flag],city_main);
						fscanf(fp,"%s \n",&str);
						for(i=0; i<10; i++)
						{
							if(strstr(str,"A02"))									//중기날씨 5일
							{
								fscanf(fp,"%s \n",&jeonla[flag][1][i].date);
								fscanf(fp,"%s \n",&jeonla[flag][1][i].time);
								fgets(jeonla[flag][1][i].weather,15,fp);
								fscanf(fp,"%d \n",&jeonla[flag][1][i].temp);
								fscanf(fp,"%d \n",&jeonla[flag][1][i].temp_max);
								fscanf(fp,"%s \n",&jeonla[flag][1][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						for(i=0; i<3; i++)
						{
							if(strstr(str,"A01"))
							{
								fscanf(fp,"%s \n",&jeonla[flag][0][i].date);
								fscanf(fp,"%s \n",&jeonla[flag][0][i].time);
								fgets(jeonla[flag][0][i].weather,15,fp);
								fscanf(fp,"%d \n",&jeonla[flag][0][i].temp);
								fscanf(fp,"%d \n",&jeonla[flag][0][i].temp_max);
								fscanf(fp,"%s \n",&jeonla[flag][0][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						break;
					}	
						
			
			}
		}
		if(!strcmp(str,"전라북도"))
			continue;
		else if(!strcmp(str,"광주ㆍ전라남도"))
		{
			strcpy(city_name,str);
			continue;
		}
		else
		{
			fscanf(fp,"%s \n",&str);
			strcpy(city_name,str);
		}
		

	}

	

	fclose(fp);
	/*
	for(k=0; k<6; k++)
	{
		printf("%s	\n",city_save_name[k]);
		printf("-----------A2시작-----------\n");
		for(i=0; i<10; i++)
		{
			printf("%s	\n",jeonla[k][1][i].date);	
			printf("%s	\n",jeonla[k][1][i].time);
			printf("%s	\n",jeonla[k][1][i].weather);
			printf("%d	\n",jeonla[k][1][i].temp);
			printf("%d	\n",jeonla[k][1][i].temp_max);
			printf("%s	\n",jeonla[k][1][i].condition);
			printf("\n");
		}
	
		printf("-----------A1시작-----------\n");
		for(i=0; i<3; i++)
		{
			printf("%s	\n",jeonla[k][0][i].date);	
			printf("%s	\n",jeonla[k][0][i].time);
			printf("%s	\n",jeonla[k][0][i].weather);
			printf("%d	\n",jeonla[k][0][i].temp);
			printf("%d	\n",jeonla[k][0][i].temp_max);
			printf("%s	\n",jeonla[k][0][i].condition);
			printf("\n");
		}
	}

	*/

	return 0;
}
