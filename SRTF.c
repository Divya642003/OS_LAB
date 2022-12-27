<<<<<<< HEAD
 #include<stdio.h>
 #include<limits.h>

 typedef struct process
{
   int pid;
   int arrival_time;
   int burst_time;
   int comp_time;
   int waiting_time;
   int turn_around_time;

   int res_time;
   int rem_time;
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

       a[i].res_time=-1;
       a[i].rem_time=a[i].burst_time;
      
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

    int time=0;
    int process_completed=0;
    int idle_time=0;

    while(process_completed<n)
    {
        int min_index=-1;
        int min_rem_time=INT_MAX;

        for(i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].rem_time!=0)
            {
                if(a[i].rem_time<min_rem_time)
                {
                    min_index=i;
                    min_rem_time=a[i].rem_time;
                }
            }
        }
         if(min_index==-1)
        {
            idle_time++;
            time++;
           
            continue;
        }

        if(a[min_index].res_time==-1)
        {
            a[min_index].res_time=time-a[min_index].arrival_time;
        }

        time++;
        a[min_index].rem_time--;

        if(a[min_index].rem_time==0)
        {
            a[min_index].comp_time=time;
            process_completed++;
        }
    }

    for(i=0;i<n;i++)
    {
        a[i].turn_around_time=a[i].comp_time-a[i].arrival_time;
        a[i].waiting_time=a[i].turn_around_time-a[i].burst_time;
    }

    //printing results
    float averg_wait_time=0,averg_turn_time=0;
    for(i=0;i<n;i++)
    {
        printf("\nPid arrival_time brust_time waiting_time completion_time turnaround_time response_time\n");
        printf("%3d %12d %10d %12d %15d %15d %13d\n",a[i].pid,a[i].arrival_time,a[i].burst_time,a[i].waiting_time,a[i].comp_time,a[i].turn_around_time,a[i].res_time);
        averg_wait_time+=a[i].waiting_time;
        averg_turn_time+=a[i].turn_around_time;
    }

    printf("\nAverage Waiting Time=%f, Average turn around time=%f",averg_wait_time/n,averg_turn_time/n);


=======
 #include<stdio.h>
 #include<limits.h>

 typedef struct process
{
   int pid;
   int arrival_time;
   int burst_time;
   int comp_time;
   int waiting_time;
   int turn_around_time;

   int res_time;
   int rem_time;
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

       a[i].res_time=-1;
       a[i].rem_time=a[i].burst_time;
      
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

    int time=0;
    int process_completed=0;

    while(process_completed<n)
    {
        int min_index=-1;
        int min_rem_time=INT_MAX;

        for(i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].rem_time!=0)
            {
                if(a[i].rem_time<min_rem_time)
                {
                    min_index=i;
                    min_rem_time=a[i].rem_time;
                }
            }
        }

        if(a[min_index].res_time==-1)
        {
            a[min_index].res_time=time;
        }

        time++;
        a[min_index].rem_time--;

        if(a[min_index].rem_time==0)
        {
            a[min_index].comp_time=time;
            process_completed++;
        }
    }

    for(i=0;i<n;i++)
    {
        a[i].turn_around_time=a[i].comp_time-a[i].arrival_time;
        a[i].waiting_time=a[i].turn_around_time-a[i].burst_time;
    }

    //printing results
    float averg_wait_time=0,averg_turn_time=0;
    for(i=0;i<n;i++)
    {
        printf("\nPid arrival_time brust_time waiting_time completion_time turnaround_time response_time\n");
        printf("%3d %12d %10d %12d %15d %15d %13d\n",a[i].pid,a[i].arrival_time,a[i].burst_time,a[i].waiting_time,a[i].comp_time,a[i].turn_around_time,a[i].res_time);
        averg_wait_time+=a[i].waiting_time;
        averg_turn_time+=a[i].turn_around_time;
    }

    printf("\nAverage Waiting Time=%f, Average turn around time=%f",averg_wait_time/n,averg_turn_time/n);


>>>>>>> 53bcafa61cba8fe35e8dc72137b171a7070ec91e
} 