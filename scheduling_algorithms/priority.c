#include<stdio.h>

int main() {
    int n,i,j;
    int at[20], bt[20], pr[20], wt[20], tat[20],ct[20];
    float awt=0, atat=0;

    printf("Enter no. of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Times:\n");
    for(i=0;i<n;i++) scanf("%d",&at[i]);

    printf("Enter BT and Priority (BT PR):\n");
    for(i=0;i<n;i++) scanf("%d%d",&bt[i], &pr[i]);

    // sort by priority
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(pr[j] > pr[j+1]){
                int t;
                t=pr[j]; pr[j]=pr[j+1]; pr[j+1]=t;
                t=bt[j]; bt[j]=bt[j+1]; bt[j+1]=t;
                t=at[j]; at[j]=at[j+1]; at[j+1]=t;
            }

    wt[0]=0;
    for(i=1;i<n;i++){
        int finish = at[i-1] + wt[i-1] + bt[i-1];
        wt[i] = finish - at[i];
        if(wt[i] < 0) wt[i] = 0;
    }

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\tCT\n");
    for(i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        ct[i]= tat[i]+at[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
                i+1, at[i], bt[i], pr[i], wt[i], tat[i],ct[i]);
    }

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", awt/n, atat/n);
    return 0;
}
