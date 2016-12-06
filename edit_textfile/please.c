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
	struct city citys[4][2][10]={0,};
	char city_name[300];
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
		if(strstr(str,"서울ㆍ인천ㆍ경기도"))
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
		if(strstr(city_name,"서울ㆍ인천ㆍ경기도"))
		{
			if(flag==0)
			{
				fscanf(fp,"%s \n",&str);
				strcpy(city_main,str);
				printf("in the flag=0\n");
				//printf("%s	\n",city_main);
				if(!strcmp(str,"서울"))
				{	
					//printf("%s \n",str);
					strcpy(city_save_name[flag],city_main);
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&citys[flag][1][i].date);
							fscanf(fp,"%s \n",&citys[flag][1][i].time);
							fgets(citys[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&citys[flag][0][i].date);
							fscanf(fp,"%s \n",&citys[flag][0][i].time);
							fgets(citys[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][0][i].condition);
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
				if(!strcmp(city_main,"인천"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&citys[flag][1][i].date);
							fscanf(fp,"%s \n",&citys[flag][1][i].time);
							fgets(citys[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&citys[flag][0][i].date);
							fscanf(fp,"%s \n",&citys[flag][0][i].time);
							fgets(citys[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag=2;
				}		
			}
			else if(flag==2)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"수원"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&citys[flag][1][i].date);
							fscanf(fp,"%s \n",&citys[flag][1][i].time);
							fgets(citys[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&citys[flag][0][i].date);
							fscanf(fp,"%s \n",&citys[flag][0][i].time);
							fgets(citys[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					flag=3;
				}		
			}
			else if(flag==3)
			{
				fscanf(fp,"%s \.n",&str);
				strcpy(city_main,str);
				if(!strcmp(city_main,"파주"))
				{
					strcpy(city_save_name[flag],city_main);	
					fscanf(fp,"%s \n",&str);
					for(i=0; i<10; i++)
					{
						if(strstr(str,"A02"))									//중기날씨 5일
						{
							fscanf(fp,"%s \n",&citys[flag][1][i].date);
							fscanf(fp,"%s \n",&citys[flag][1][i].time);
							fgets(citys[flag][1][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp);
							fscanf(fp,"%d \n",&citys[flag][1][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][1][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					for(i=0; i<3; i++)
					{
						if(strstr(str,"A01"))
						{
							fscanf(fp,"%s \n",&citys[flag][0][i].date);
							fscanf(fp,"%s \n",&citys[flag][0][i].time);
							fgets(citys[flag][0][i].weather,15,fp);
							//fscanf(fp,"%s \n",&A02[i].weather);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp);
							fscanf(fp,"%d \n",&citys[flag][0][i].temp_max);
							fscanf(fp,"%s \n",&citys[flag][0][i].condition);
						}
						fscanf(fp,"%s \n",&str);
					}
					//flag=2;
				}		
			}
		}
	}
	

	fclose(fp);
/*	for(k=0; k<flag; k++)
	{
		*/
//		k=0;

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
	return 0;

}
