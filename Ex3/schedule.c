#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct process{
	char pid[20];
	float arrt;
	float burst;
	float wt;
	float tt;
};

void findWaitingTime(struct process s[], int n) 
{ 
    int service_time[n]; 
    service_time[0] = 0; 
    s[0].wt = 0;
  
    for (int i = 1; i < n ; i++) 
    { 
        service_time[i] = service_time[i-1] + s[i-1].burst; 
  
        s[i].wt = service_time[i] - s[i].arrt; 

        if (s[i].wt < 0) 
            s[i].wt = 0; 
    } 
} 
    
void findTurnAroundTime( struct process s[], int n)  
{   
    for (int  i = 0; i < n ; i++)  
        s[i].tt = s[i].burst + s[i].wt;  
}  
    
void findavgTime( struct process s[], int n)  
{  
    int total_wt = 0, total_tat = 0;  
    
    findWaitingTime(s, n);  
     
    findTurnAroundTime(s, n);  
    
    printf("\nProcesses   Burst time   Waiting time   Turn around time\n\n");  
    
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + s[i].wt;  
        total_tat = total_tat + s[i].tt;  
        printf("   %d ",(i+1)); 
        printf("       %f ", s[i].burst ); 
        printf("       %f",s[i].wt ); 
        printf("       %f\n",s[i].tt );  
    }  
    float si=(float)total_wt / (float)n; 
    float t=(float)total_tat / (float)n; 
    printf("\nAverage waiting time = %f",si); 
    printf("\n"); 
    printf("Average turn around time = %f ",t);  
}  

int main()
{
	int ch=1;
	do
	{
		printf("\n\tCPU SCHEDULING ALGORITHMS");
		printf("\n1. FCFS");
		printf("\n2. SJF");
		printf("\n3. EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		int nop;
		printf("\nEnter number of processes: ");
		scanf("%d", &nop);
		struct process s[nop];
		for(int i=0;i<nop;i++)
		{
			printf("\n Enter Process ID: ");	
			scanf("%s", s[i].pid);
			printf("\n Enter Arrival Time: ");
			scanf("%f", &s[i].arrt);
			printf("\n Enter Burst Time: ");
			scanf("%f", &s[i].burst);
		}
		if(ch == 1 || ch == 2)
		{
			if(ch == 1)
			{			
				findavgTime(s, nop);
			}
			if(ch == 2)
			{
				printf("\n SJF Scheduling");
				printf("\n 1. Non Preemptive");
				printf("\n 2. Pre Emptive");
				scanf("%d", &ch);
				if(ch == 1)
				{
					for(int i = 0; i<nop; i++)
						s[i].arrt = 0;
				}
				else if(ch == 2)
				{
					
				}


			}
		}
		
	}while(ch!=3);
	return 0;
}
				
			
				
