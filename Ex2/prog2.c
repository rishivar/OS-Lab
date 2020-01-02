#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
int main(int argc, char *argv[])
{

	struct dirent *de;
	
	if(argc > 2)
	{
		printf(" Error! Incorrect number of Arguments Provided");
		return 0;
	}

	DIR *dr = opendir(argv[1]);

	if(dr == NULL)
	{
		printf("\n Could not open directory");
		return 0;
	}

	while((de = readdir(dr)) != NULL)
		printf("%s \n", de->d_name);

	closedir(dr);
	return 0;

}
