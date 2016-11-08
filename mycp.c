#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd,fd_copy;
	char buf[1000];
	struct stat sb;


	if(argc != 3)		
	{	
		printf("Error!!! \n");
	}
	
	fd = open(agrv[1],O_RDONLY);
	fd_copy = open(argv[2],O_WRONLY | O_CREAT | O_APPEND,0666);

	
