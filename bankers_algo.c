#include<stdio.h>
    int main()
    {
        int i,n,m;
        printf("____________________________________________________________________________\n");
        printf("ENTER THE NUMBER OF PROCESS :::: ");
        scanf("%d",&n);
        printf("ENTER THE NUMBER OF RESOURCES :::: ");
        scanf("%d",&m);
           int process[n];
           int allocation[n][m];
           int request[n][m];
         printf("ENTER \n   PROCESS_ID    ALLOCATION   REQUESTED  \n");
         printf("\t \t  X  Y  Z\tX  Y  Z \n");
         
         for(int j=0;j<n;j++)
         {
            scanf("%d",&process[j]);
            for(i=0;i<m;i++)
            {
               scanf("%d",&allocation[j][i]);
               scanf("%d",&request[j][i]);
            }
            printf("\n");
         }
         int max;
         scanf("%d",&max);
         int available[1][m];
          for(int j=0;j<m;j++)
         {
            int sum=0;
            for(i=0;i<n;i++)
            {
              sum+=allocation[i][j];
            }
            available[0][m]=sum-max;
            printf("\n");
         }

         for(i=0;i<m;i++)
         {
            printf("%d\t",available[0][i]);
         }
    }                  