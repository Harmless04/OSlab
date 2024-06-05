#include<stdio.h>
int main()
{
   int n,at[10],bt[10],wt[10],tat[10],ct[10],p[10],sum,i,j,k,temp;
   float totaltat=0,totalwt=0;
   printf("Enter the total number of processes:");
   scanf("%d",&n);
   printf("\nEnter the process number:\n");
   for(i=0;i<n;i++)
       scanf("%d",&p[i]);
   printf("\nEnter The Process Burst Time\n");
    for(i=0;i<n;i++)
    {
             printf("Enter Burst time of process[%d]:",i+1);
             scanf("%d",&bt[i]);
    }
   /* Apply Bubble sort to sort according to burst time and process number */
    for(i=0;i<n;i++)
    {
          for(j=0;j<n-i-1;j++)
         {
               if(bt[j]>bt[j+1])
               {
                   temp=bt[j];
                   bt[j]=bt[j+1];
                   bt[j+1]=temp;

                  temp=p[j];
                  p[j]=p[j+1];
                  p[j+1]=temp;
                }
              }
           }
    /*Calculate completion time of processes*/
  sum=0;
  for(j=0;j<n;j++)
  {
          sum=sum+bt[j];
 ct[j]=sum;
 printf("%d\t",ct[j]);
  }
   /*Calculate Turn Around time */
   for(k=0;k<n;k++)
  {
           tat[k]=ct[k];
           totaltat=totaltat+tat[k];
  }
     /*  Calculate Waiting time  */
  for(k=0;k<n;k++)
  {
           wt[k]=tat[k]-bt[k];
  totalwt=totalwt+wt[k];
  }

   printf("\nProcess\tBT\tTAT\tWT\n\n\n");
 for(i=0;i<n;i++)
 {
      printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t\n",i+1,bt[i],tat[i],wt[i]);
}
    printf("\nAverage TurnaroundTime:%f\n",totaltat/n);
    printf("\nAverage Waiting Time:%f",totalwt/n);
 
    return 0;
}
