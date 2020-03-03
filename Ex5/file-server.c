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
char *a,c,*turn,*avail;

id=shmget(111,50,IPC_CREAT | 00666);
av=shmget(112,50,IPC_CREAT | 00666);
avail=shmat(av,NULL,0);

a=shmat(id,NULL,0);
char s[100];
turn=shmat(av,NULL,0);
turn[0]=1;
printf("Server Running : ");
printf("Waiting for File Name \n");
//scanf("%s\n",s);
//strcpy(a,s);
avail[0]='N';
while(avail[0]=='N');
//turn[0]=2;
//while(turn[0]==2);

printf("File Name : %s",a);
FILE *f1=fopen(a,"r");
if(f1!=NULL)
{
	fread(a,50,1,f1);
	printf("\n\nFile Contents :\n\n%s\n",a);
}
else
{
	printf("\nFile Doesnt Exist !!!\n");
	strcpy(a,"-1");
}
avail[0]='N';
shmdt(a);
shmdt(avail);
return 0;
}
