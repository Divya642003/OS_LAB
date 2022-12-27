#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int n,i,j;
    printf("Enter number of requests:");
    scanf("%d",&n);

    int arr[n];
    int visit[n];

    printf("Enter requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        visit[i]=0;
    }

     int head;
    printf("Enter initial position of head:");
    scanf("%d",&head);

    int seektime;
    printf("Enter seek time:");
    scanf("%d",&seektime);

     int seekTime[n];
    int count=0;
    int totalSeekTime=0;

    for(i=0;i<n;i++)
    {
        int min_index=-1,min=INT_MAX;
        for(j=0;j<n;j++)
        {
            if(abs(head-arr[i])<min&&visit[i]==0&&arr[i]!=head)
            {
                min=abs(head-arr[i]);
                min_index=i;
            }
        }
        visit[min_index]=1;

         int temp=abs(head-arr[min_index]);
        head=arr[min_index];

        count+=temp;
        totalSeekTime+=temp*seektime;
        seekTime[min_index]=totalSeekTime;
    }

     printf("\nRequest\tSeek_Time");
    for(i=0;i<n;i++)
    {
        printf("\n%7d\t%9d",arr[i],seekTime[i]);
    }
    
    printf("\n\nTotal seek operations: %d",count);
    printf("\nTotal seek time: %d",totalSeekTime);
}