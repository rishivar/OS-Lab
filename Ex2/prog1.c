#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, char *argv[])
{
	int src, dest, rd, wrt;
	char *buff[1024];
	
	if(argc!=3)
	{
		printf("\n Error : more arguments provided ");
		exit(0);
	}

	src = open(argv[1], O_RDONLY);
	
	if(src == -1)
	{
		printf("\n Error opening source file");
		exit(0);
	}

	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	
	if(dest == -1)
	{
		printf("\n Error opening Destination file");
		exit(0);
	}

	while((rd = read(src, buff, 1024))>0)
	{
		if(write(dest, buff, rd)!=rd)
		{
			printf("Error in writing data");
		}
	}

	if(rd == -1)
		printf("\nError in reading data from %s\n",argv[1]);
	
	if(close(src) == -1)
		printf("\nError in closing file %s\n",argv[1]);
 
	if(close(dest) == -1)
		printf("\nError in closing file %s\n",argv[2]);

	exit(EXIT_SUCCESS);

}
//sandy

