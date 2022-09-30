#include<stdio.h>

void waiting_time(int processes[],int n,int bt[],int wt[])
{
    
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i] = bt[i-1]+wt[i-1];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t\t %d\n",processes[i],wt[i]);
    }
  
}

void Turnaround_time(int processes[],int n,int bt[],int wt[],int tat[])
{
    
    for(int i=0;i<n;i++)
    {
        tat[i] = bt[i]+wt[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t\t %d\n",processes[i],tat[i]);
    }
  
}

void average_time(int processes[],int n,int bt[],int wt[],int tat[])
{
  int total_waiting_time=0;
  int total_turnaround_time=0;
    for(int i=0;i<n;i++)
    {
        total_waiting_time = total_waiting_time+wt[i];
        total_turnaround_time = total_turnaround_time+tat[i];
    }
    printf("%d\t\t\t %d\n",total_waiting_time/n,total_turnaround_time/n);
}
int main()
{
    
    int n;
    
    printf("\n Enter the number of processes :: ");
    scanf("%d",&n);
    int processes[n];
    int bt[n];
    int wt[n];
    int tat[n];
    printf("_________________________________________________________________________\n");
    printf(" ENTER THE PROCESSES :    BURST TIME :    \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&processes[i],&bt[i]);
    }
    //printf("Hello");
    printf("_________________________________________________________________________\n");
    printf("THE WAITING TIME FOR %d PROCEESE IS :: \n",n);
    waiting_time(processes,n,bt,wt);
    printf("_________________________________________________________________________\n");
    printf("THE TURN_AROUND TIME FOR %d PROCEESE IS :: \n",n);
    Turnaround_time(processes,n,bt,wt,tat);
     printf("_________________________________________________________________________\n");
    printf("THE AVERAGE WAITING TIME AND AVERAGE TURN_AROUND TIME FOR %d PROCEESE IS :: \n",n);
    average_time(processes,n,bt,wt,tat);
 }