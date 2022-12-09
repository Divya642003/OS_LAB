#include<stdio.h>

typedef struct process
{
   int pid;
   int arrival_time;
   int burst_time;
   int comp_time;
   int waiting_time;
   int turn_around_time;
}process;

int main()
{
    int n,i;
    printf("enter the number of processes :: ");
    scanf("%d",&n);
    process a[n];
    printf(" enter the data of %d processes \n",n);
    printf(" process id     arrival time    burst time ");
    for(i=0;i<n;i++)
    {
      scanf("%d %d %d",&a[i].pid,&a[i].arrival_time,&a[i].burst_time);

      if(i>0)
      {
        process key = a[i];
        int j= i-1;
        while(j>=0&&a[j].arrival_time>key.arrival_time)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
      }
    }
    /*printf(" process id     arrival time    burst time \n");
    for(i=0;i<n;i++)
    {
        printf("%3d %12d %12d \n",a[i].pid,a[i].arrival_time,a[i].burst_time);
    }*/

    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            a[i].waiting_time=0;
            a[i].comp_time=a[i].arrival_time+a[i].burst_time;
            a[i].turn_around_time=a[i].comp_time-a[i].arrival_time;
        }
        else{

            a[i].comp_time=a[i-1].comp_time+a[i].burst_time;
            a[i].turn_around_time=a[i].comp_time-a[i].arrival_time;
            a[i].waiting_time=a[i].turn_around_time-a[i].burst_time;
        }
    }

     float averg_wait_time=0,averg_turn_time=0;
    for(i=0;i<n;i++)
    {
        printf("\nPid arrival_time brust_time waiting_time completion_time turnaround_time\n");
        printf("%3d %12d %10d %12d %15d %15d\n",a[i].pid,a[i].arrival_time,a[i].burst_time,a[i].waiting_time,a[i].comp_time,a[i].turn_around_time);
        averg_wait_time+=a[i].waiting_time;
        averg_turn_time+=a[i].turn_around_time;
    }

    printf("\nAverage Waiting Time=%f, Average turn around time=%f",averg_wait_time/n,averg_turn_time/n);

}