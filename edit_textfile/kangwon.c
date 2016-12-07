#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"

struct city kangwon[4][2][10]={0,};



int changekangwon()
{
	//char *c=0;
	char str[500]={0,};
	
	char city_name[300];
	char city_name1[300];
	char city_main[100]={0,};
	char city_save_name[4][100]={0,};
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
		if(strstr(str,"강원도영서"))
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
		if(strstr(city_name,"강원도영서"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				//printf("%s	\n",city_main);
				if(!strcmp(str,"춘천"))
				{	
					//printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(kangwon[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].time);
							fgets(kangwon[flag][1][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(kangwon[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].time);
							fgets(kangwon[flag][0][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].condition);
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
				if(!strcmp(city_main,"원주"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(kangwon[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].time);
							fgets(kangwon[flag][1][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(kangwon[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].time);
							fgets(kangwon[flag][0][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =2;
					//break;
				}		
			}
		}
		if(strstr(city_name,"강원도영동"))
		{
			if(flag==2)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				//printf("in the flag=0\n");
				//printf("%s	\n",city_main);
				if(!strcmp(str,"강릉"))
				{	
					//printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(kangwon[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].time);
							fgets(kangwon[flag][1][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(kangwon[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].date);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].time);
							fgets(kangwon[flag][0][i].weather,18,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp);
							fscanf(fp,"%d \n",&kangwon[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&kangwon[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
				}		
			}
		}


		if(!strcmp(str,"강원도영서"))
			continue;
		else if(!strcmp(str,"강원도영동"))
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

	return 0;

}
