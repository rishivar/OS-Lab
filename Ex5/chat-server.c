# include <sys/ipc.h>
# define  NULL 0
# include <sys/shm.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio_ext.h>
# include <errno.h>
# include <fcntl.h>
# include <ctype.h>
# define  BUFF_SIZE 1024

int main()
{
	char *avail,*usr1,*usr2;
	int id,id1,id2;
	
	id=shmget(111,50,IPC_CREAT | 00666);
	id1=shmget(112,50,IPC_CREAT | 00666);
	id2=shmget(113,50,IPC_CREAT | 00666);
	
	avail=shmat(id,NULL,0);
	usr1=shmat(id1,NULL,0);
	usr2=shmat(id2,NULL,0);
	strcpy(usr1,"-1");
	strcpy(usr2,"-1");
	while(1){
	
		printf("You    : ");
		scanf (" %[^\n]",usr1);
		
		if(strcmp(usr1,"exit")==0){
			avail[0]='Y';
			shmdt(usr1);
			shmctl(id1, IPC_RMID,NULL);
			break;
		}
		
		avail[0]='Y';
		while(avail[0]=='Y');
		
		printf("Client : %s\n",usr2);
		
				
	}
}
