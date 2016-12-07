#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"

struct city gyeongsang[4][2][10]={0,};

int changegyeongsang()
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
		if(strstr(str,"대구ㆍ경상북도"))
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
		if(strstr(city_name,"대구ㆍ경상북도"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"대구"))
				{	
					printf("%s \n",str);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(gyeongsang[flag][1][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
							fgets(gyeongsang[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(gyeongsang[flag][0][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
							fgets(gyeongsang[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
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
				if(!strcmp(city_main,"안동"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(gyeongsang[flag][1][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
							fgets(gyeongsang[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(gyeongsang[flag][0][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
							fgets(gyeongsang[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
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
				if(!strcmp(str,"포항"))
				{	
					//printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(gyeongsang[flag][1][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
							fgets(gyeongsang[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(gyeongsang[flag][0][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
							fgets(gyeongsang[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag=3;
				}		
			}
			
		}
		if(strstr(city_name,"부산ㆍ울산ㆍ경상남도"))
		{
			if(flag==3)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"부산"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(gyeongsang[flag][1][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
							fgets(gyeongsang[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(gyeongsang[flag][0][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
							fgets(gyeongsang[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag =4;
				}		
			}
			else if(flag==4)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				if(!strcmp(str,"울산"))
				{	
					//printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							strcpy(gyeongsang[flag][1][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
							fgets(gyeongsang[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							strcpy(gyeongsang[flag][0][i],city_main);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
							fgets(gyeongsang[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
							fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag=5;
				}		
			}
			else if(flag==5)
			{
					fscanf(fp,"%s \n",&str);
					strcpy(city_main,str);
					if(!strcmp(str,"창원"))
					{	
						//printf("%s \n",str);
						strcpy(city_save_name[flag],city_main);
						fscanf(fp,"%s \n",&str);
						for(i=0; i<10; i++)
						{
							if(strstr(str,"A02"))									//중기날씨 5일
							{
								strcpy(gyeongsang[flag][1][i],city_main);
								fscanf(fp,"%s \n",&gyeongsang[flag][1][i].date);
								fscanf(fp,"%s \n",&gyeongsang[flag][1][i].time);
								fgets(gyeongsang[flag][1][i].weather,15,fp);
								//fscanf(fp,"%s \n",&A02[i].weather);
								fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp);
								fscanf(fp,"%d \n",&gyeongsang[flag][1][i].temp_max);
								fscanf(fp,"%s \n",&gyeongsang[flag][1][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						for(i=0; i<3; i++)
						{
							if(strstr(str,"A01"))
							{
								strcpy(gyeongsang[flag][1][i],city_main);
								fscanf(fp,"%s \n",&gyeongsang[flag][0][i].date);
								fscanf(fp,"%s \n",&gyeongsang[flag][0][i].time);
								fgets(gyeongsang[flag][0][i].weather,15,fp);
								//fscanf(fp,"%s \n",&A02[i].weather);
								fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp);
								fscanf(fp,"%d \n",&gyeongsang[flag][0][i].temp_max);
								fscanf(fp,"%s \n",&gyeongsang[flag][0][i].condition);
							}
							fscanf(fp,"%s \n",&str);
						}
						break;
					}		
			
			}
		}
		if(!strcmp(str,"대구ㆍ경상북도"))
			continue;
		else if(!strcmp(str,"부산ㆍ울산ㆍ경상남도"))
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
