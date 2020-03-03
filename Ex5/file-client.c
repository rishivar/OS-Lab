#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include <sys/wait.h>
#include <stdio_ext.h>
#include<ctype.h>

// parent writing a char in shared memory and child reads it and prints it.
int main()
{
int id,av;
char *file,*b,c,*avail;
av=shmget(112,50,0);
avail=shmat(av,NULL,0);

id=shmget(111,50,0);
b=shmat(id,NULL,0);

printf("Enter File Name : \n");
scanf("%s",file);
strcpy(b,file);
avail[0]='Y';
while(avail[0]=='Y');

if(strcmp(b,"-1")==0)
{
	printf("\nFile Doesnt Exist !!!\n");
}
else
{
	printf("\nEnter New File Name : \n");
	scanf("%s",file);
	
	FILE* fptr=fopen(file,"w");
	printf("\nFile Contents :\n\n%s\n",b);
	fprintf(fptr,"%s",b);
}

shmdt(b);
shmdt(avail);
shmctl(id, IPC_RMID,NULL);
shmctl(av, IPC_RMID,NULL);

return 0;
}
