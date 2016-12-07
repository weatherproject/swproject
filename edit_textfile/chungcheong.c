#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"

struct city chungcheong[4][2][10]={0,};



int changechungcheong()
{
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
		fscanf(fp,"%s \n",&str);

		if(strstr(str,"충청북도"))
		{
			flag=0;
			strcpy(city_name,str);
			break;
		}
	}
	
	
	while(feof(fp) ==0)
	{
		if(strstr(city_name,"충청북도"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"청주"))
				{	
					printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(chungcheong[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].time);
							fgets(chungcheong[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(chungcheong[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].time);
							fgets(chungcheong[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =1;
				}		
			}
			
		}
		if(strstr(city_name,"대전ㆍ세종ㆍ충청남도"))
		{
			if(flag==1)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"대전"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(chungcheong[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].time);
							fgets(chungcheong[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(chungcheong[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].time);
							fgets(chungcheong[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =2;
				}		
			}
			else if(flag==2)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"서산"))
				{	
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(chungcheong[flag][1][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].time);
							fgets(chungcheong[flag][1][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(chungcheong[flag][0][i].name,city_main);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].date);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].time);
							fgets(chungcheong[flag][0][i].weather,15,fp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp);
							fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&chungcheong[flag][0][i].condition);
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
					if(!strcmp(str,"세종"))
					{	
						//printf("%s \n",str);
						strcpy(city_save_name[flag],city_main);
						fscanf(fp,"%s \n",&str);
						for(i=0; i<10; i++)
						{
							if(strstr(str,"A02"))									//중기날씨 5일
							{
								strcpy(chungcheong[flag][1][i].name,city_main);
								fscanf(fp,"%s \n",&chungcheong[flag][1][i].date);
								fscanf(fp,"%s \n",&chungcheong[flag][1][i].time);
								fgets(chungcheong[flag][1][i].weather,15,fp);
								fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp);
								fscanf(fp,"%d \n",&chungcheong[flag][1][i].temp_max);
								fscanf(fp,"%s \n",&chungcheong[flag][1][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						for(i=0; i<3; i++)
						{
							if(strstr(str,"A01"))
							{
								strcpy(chungcheong[flag][0][i].name,city_main);
								fscanf(fp,"%s \n",&chungcheong[flag][0][i].date);
								fscanf(fp,"%s \n",&chungcheong[flag][0][i].time);
								fgets(chungcheong[flag][0][i].weather,15,fp);
								fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp);
								fscanf(fp,"%d \n",&chungcheong[flag][0][i].temp_max);
								fscanf(fp,"%s \n",&chungcheong[flag][0][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						break;
					}		
			
			}
		}
		if(!strcmp(str,"충청북도"))
			continue;
		else if(!strcmp(str,"대전ㆍ세종ㆍ충청남도"))
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
