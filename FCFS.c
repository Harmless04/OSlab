#include <stdio.h>
int main(){

 int n,at[10],bt[10],ct[10],tat[10],wt[10],sum,i,j,k;
 float totaltat =0 , totalwt = 0;
 printf("enter the total number of process ");
 scanf("%d",&n);
 printf("enter the process arrival time and burst time\n");
 for(i=0;i<n;i++){
  printf("enter the arrival time of the process [%d]",i+1);
  scanf("%d",&at[i]);
  printf("enter the burst time of the process[%d]",i+1);
  scanf("%d",&bt[i]);
 }
 /*calculate completion time of processs*/
 sum=at[0];
 for(j=0;j<n;j++){

  sum=sum+bt[j];
  ct[j]=sum;

 }
 /*calculate turn around time*/
for(k=0;k<n;k++){

  tat[k]=ct[k]-at[k];
  totaltat=totaltat+tat[k];

}
/*calculating waiting time*/
for(k=0;k<n;k++){

  wt[k]=tat[k]-bt[k];
  totalwt=totalwt+wt[k];

}
printf("\nprocess\tAT\tBT\tCT\tTAT\tWT\n\n\n");
for(i=0;i<n;i++){

  printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

}


}
