#include<stdio.h>

typedef struct process{
    int p_id;
    int arrival_time;
    int burst_time;
    int comp_time;
    int waiting_time;
    int turnaround_time;
}process;

int main()
{
    int n;
    printf("\n ENTER THE TOTAL NUMBER OF PROCESSES :: ");
    scanf("%d",&n);
    process array[n];
    int i;
    printf("\nENTER                            P_ID    ARRIVAL_TIME    BURST_TIME  ");
    for(i=0;i<n;i++)
    {
        printf("\nENTER RECORD FOR PROCESS %d ",i+1);
        scanf("%3d %5d %7d",&array[i].p_id,&array[i].arrival_time,&array[i].burst_time);

        if(i>0)
        {
         process key=array[i];
            int j=i-1;
            while(j>=0&&key.arrival_time<array[j].arrival_time)
            {
                array[j+1]=array[j];
                j=j-1;
            }
            array[j+1]=key;
        }
    }

   /* for(i=0;i<n;i++)
    {
        printf("\n%d",array[i].p_id);
    }*/

    int idle_time=0;
    int time=array[0].arrival_time;
    for(i=0;i<n;i++)
    {
        if(array[i].arrival_time>time)
        {
            idle_time++;
            time++;
            i--;
            continue;
        }
        array[i].comp_time=time+array[i].burst_time;
        array[i].turnaround_time=array[i].comp_time-array[i].arrival_time;
        array[i].waiting_time=array[i].turnaround_time-array[i].burst_time;
                  
        time+=array[i].burst_time;
    }
    float avg_wait_time =0;
    float cpu_utilization =((time-idle_time)/(float)time)*100;
 printf("\n  P_ID    ARRIVAL_TIME    BURST_TIME    COMP_TIME   TURNAROUND_TIME   WAITING_TIME ");
for(i=0;i<n;i++)
    {
        printf("\n%3d %7d %15d %15d %15d %15d",array[i].p_id,array[i].arrival_time,array[i].burst_time,array[i].comp_time,array[i].turnaround_time,array[i].waiting_time);
        avg_wait_time+=array[i].waiting_time;
    }   

    printf("\n TOTAL AVERAGE WAITING TIME IS :: %f",avg_wait_time/n);
    printf("\n TOTAL CPU UTILIZATION IN percent IS :: %f",cpu_utilization ); 
}