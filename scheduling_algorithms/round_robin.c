// Round Robin Scheduling with Arrival Time
#include<stdio.h>
#define N 20

int main() {
    int n, i, tq;
    int at[N], bt[N], rt[N], ct[N], wt[N], tat[N];
    int time = 0, comp = 0;
    float awt = 0, atat = 0;
    int gP[200], gE[200]; // process number and end time of each slice
    int g = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];          // remaining time = burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(comp < n) {
        int done = 1;           // assume no process will run in this cycle

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {   // process is ready
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;   // completion time
                    comp++;
                }
                gP[g] = i;
                gE[g] = time;
                g++;
            }
        }

        if(done)      // no ready process, CPU idle
            time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
        awt  += wt[i];
        atat += tat[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", awt/n, atat/n);
    
    printf("\nGantt Chart:\n");
    int start = 0;
    printf("%d", start);
    for(i = 0; i < g; i++) {
        printf(" |P%d| %d", gP[i] + 1, gE[i]);
        start = gE[i];
    }

    return 0;
}
