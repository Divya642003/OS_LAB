#include<stdio.h>
int main()
{
    int n ,i,overall_time=0;
    int index =-1;
    printf("enter total number of elements in request array : ");
    scanf("%d",&n);
    int rq[n],seek_time[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
        if(i>0)
        {
            int key =rq[i];
            int j = i-1;
            while(key<rq[j]&&j>=0)
            {
                rq[j+1]=rq[j];
                j--;
            }
            rq[j+1]=key;
            if(rq[i]<=50)
            {
                index=i;
            }
        }
    }
    int head,result=0;
    printf("enter the value of initial head : ");
    scanf("%d",&head);
    int time;
    printf("enter the seek time for each seek operation : ");
    scanf("%d",&time);
    
    for(int j=index;j>=0;j--)
    {
        int temp = head-rq[i];
        head=rq[i];
        result += temp;
        seek_time[i]=time*temp;
        overall_time+=seek_time[i];

    }
    int temp = head-0;
    head=0;
    result+=temp;
    overall_time+=temp*time;
 
    for(int j=index+1;j<n;j++)
    {
        int temp = rq[j]-head;
        head=rq[j];
        result += temp;
        seek_time[j]=time*temp;
        overall_time+=seek_time[j];

    }

    printf("overall operation :: %d ",result);
    printf("\noverall time  :: %d",overall_time);

}