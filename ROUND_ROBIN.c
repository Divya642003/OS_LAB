<<<<<<< HEAD
 #include<stdio.h>
 

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
   int in_q;
}process;

int front=-1,end=-1;

void enqueue(int queue[],int n,int p)
{
    if((end+1)%n==front)
    {
        printf("overflow ");
        return;
    }

    if(front==end)
    {
        front=0;
    }
    end=(end+1)%n;
    queue[end]=p;
}

int dequeue(int queue[],int n)
{
    if(end==-1)
    {
        printf("underflow");
        return;
    }

    int temp =queue[front];
    if(front==end)
    {
        front=-1;
        end=-1;
    }

    front = (front+1)%n;
}


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

    int quant;
    printf("enter the value of quant :");
    scanf("%d",&quant);

    int queue[n];
    enqueue(queue,n,0);
    a[0].in_q=1;

    int time=a[0].arrival_time;
    int process_completed=0;

    while(process_completed<n)
    {
        int temp=dequeue(queue,n);
        a[temp].in_q=0;

        if(a[temp].res_time==-1)
        {
            a[temp].res_time=time;
        }
        a[temp].rem_time-=quant;

        if(a[temp].res_time<=0)
        {
            time = time + quant + a[temp].rem_time;
            a[temp].comp_time=time;
            process_completed++;

        for(int i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].res_time==-1&&a[i].in_q==0)
            {
                enqueue(queue,n,i);
                a[i].in_q=1;
            }
        }
        }

        else{
            time+=quant;
            for(int i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].res_time==-1&&a[i].in_q==0)
            {
                enqueue(queue,n,i);
                a[i].in_q=1;
            } 
        }
        }

        enqueue(queue,n,temp);
                a[temp].in_q=1;
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
   int in_q;
}process;

int front=-1,end=-1;

void enqueue(int queue[],int n,int p)
{
    if((end+1)%n==front)
    {
        printf("overflow ");
        return;
    }

    if(front==end)
    {
        front=0;
    }
    end=(end+1)%n;
    queue[end]=p;
}

int dequeue(int queue[],int n)
{
    if(end==-1)
    {
        printf("underflow");
        return;
    }

    int temp =queue[front];
    if(front==end)
    {
        front=-1;
        end=-1;
    }

    front = (front+1)%n;
}


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

    int quant;
    printf("enter the value of quant :");
    scanf("%d",&quant);

    int queue[n];
    enqueue(queue,n,0);
    a[0].in_q=1;

    int time=a[0].arrival_time;
    int process_completed=0;

    while(process_completed<n)
    {
        int temp=dequeue(queue,n);
        a[temp].in_q=0;

        if(a[temp].res_time==-1)
        {
            a[temp].res_time=time;
        }
        a[temp].rem_time-=quant;

        if(a[temp].res_time<=0)
        {
            time = time + quant + a[temp].rem_time;
            a[temp].comp_time=time;
            process_completed++;

        for(int i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].res_time==-1&&a[i].in_q==0)
            {
                enqueue(queue,n,i);
                a[i].in_q=1;
            }
        }
        }

        else{
            time+=quant;
            for(int i=0;i<n;i++)
        {
            if(a[i].arrival_time<=time&&a[i].res_time==-1&&a[i].in_q==0)
            {
                enqueue(queue,n,i);
                a[i].in_q=1;
            } 
        }
        }

        enqueue(queue,n,temp);
                a[temp].in_q=1;
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