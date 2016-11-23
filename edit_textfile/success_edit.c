#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city{
	char date[30];
	char time[10];
	char weather[10];
	int temp;
	int temp_max;
	char condition[10];
};


int main()
{
	//char *c=0;
	char str[100];
	struct city m[3]={0,};
	char city_name[100];
	char city_main[100];
	int i=0;
	FILE *fp = fopen("seoul.txt","rt");
	if(fp == NULL)
	{
		printf("실패");
		return 1;
	}
	while(feof(fp) ==0)
	{
		//fscanf(fp,"%s",&c);
		//printf("%s\n",c);
		//fgets(str,sizeof(str),fp);
		fscanf(fp,"%s \n",&str);

		if(strstr(str,"서울ㆍ인천ㆍ경기도"))
		{

			//printf("1차성공");
			fscanf(fp,"%s \n",&str);
			if(strstr(str,"서울"))
			{
				fscanf(fp,"%s \n",&str);
				for(i=0; i<3; i++)
				{
					if(strstr(str,"A02"))
					{
						fscanf(fp,"%s \n",&m[i].date);
						fscanf(fp,"%s \n",&m[i].time);
						fscanf(fp,"%s \n",&m[i].weather);
						fscanf(fp,"%d \n",&m[i].temp);
						fscanf(fp,"%d \n",&m[i].temp_max);
						fscanf(fp,"%s \n",&m[i].condition);
					}
					fscanf(fp,"%s \n",&str);
				}
			
			}
		}
		//puts(str);
	}
	
	fclose(fp);
	for(i=0; i<3; i++)
	{
		printf("%s	\n",m[i].date);	
		printf("%s	\n",m[i].time);
		printf("%s	\n",m[i].weather);
		printf("%d	\n",m[i].temp);
		printf("%d	\n",m[i].temp_max);
		printf("%s	\n",m[i].condition);
		printf("\n");
	}
	return 0;

}
