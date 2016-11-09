#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd,fd_copy;
	int cnt;
	char buf[1000];
	struct stat sb;


	if(argc != 3)		
	{	
		printf("Error!!! \n");
	}
	
	fd = open(argv[1],O_RDONLY);
	fd_copy = open(argv[2],O_WRONLY | O_CREAT | O_APPEND,0666);

	while(1)
	{
		cnt = read(fd,buf,1000);
		write(fd_copy,buf,cnt);
		if(cnt == 0 )
			break;
	}
	
	lstat(argv[1],&sb);
	chmod(argv[2],sb.st_mode);

	close(fd);
	close(fd_copy);
		
	return 0;
}






