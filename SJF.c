#include<stdio.h>
#include<limits.h>

typedef struct process{
    int p_id;
    int arrival_time;
    int burst_time;
    int comp_time;
    int waiting_time;
    int turnaround_time;
    int rem_time;

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
        array[i].rem_time=array[i].burst_time;
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
    int process_completed =0;

    while(process_completed<n)
    {
        int min_index =-1,min_rem_time=INT_MAX;

      for(i=0;i<n;i++)
     {
        
        if(array[i].arrival_time<=time&&array[i].rem_time!=0)
        {
            if(array[i].rem_time<min_rem_time)
            {
                min_index=i;
                min_rem_time=array[i].rem_time;
            }
        }
     }
        if(min_index==-1)
        {
            idle_time++;
            time++;
           
            continue;
        }
        array[min_index].comp_time=time+array[min_index].burst_time;
        array[min_index].turnaround_time=array[min_index].comp_time-array[min_index].arrival_time;
        array[min_index].waiting_time=array[min_index].turnaround_time-array[min_index].burst_time;
                  
        time+=array[min_index].burst_time;
        process_completed++;
        array[min_index].rem_time-=array[min_index].burst_time;

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