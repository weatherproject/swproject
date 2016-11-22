#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char*argv[])
{
	int i,j;
	int fd_in;
	int fd_out;
	char buf[1];
	int nb;
	int ch_in;
	int ch_out;
	struct stat sb;

	if(argc !=3)//input 3
	{
		fprintf(stderr, "usage:opentest filename\n");
		exit(0);
	}
	fd_in = open(argv[1],O_RDONLY);
	fd_out = open(argv[2],O_WRONLY | O_CREAT | O_APPEND | O_TRUNC);

	while((nb=read(fd_in,buf,1))>0)//until file end
	{

		j=1;
		for(i=0; buf[i] != '\0'; i++)

		{
			if(buf[i] =='\n' ||buf[i] == ' ' || buf[i]=='\t'||buf[i]=='s')
			//if buf have enter or space or tap 
			{
				j=0;//flag become 0

			}

		}
		if(j==1)//if flag become 1 = this buf have font 
		{
			write(fd_out,buf,nb);//write that font 
			printf("%s 1",buf);//confirm on window 
		}


	}
	//authority copy
	lstat(argv[1],&sb);
	ch_in=sb.st_mode;
	ch_out=chmod(argv[2],ch_in);
	close(fd_in);
	close(fd_out);
	return 0;
}

