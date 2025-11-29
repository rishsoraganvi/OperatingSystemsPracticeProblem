//Write a program for implementation of the cpu scheduling algorithm First Come First Serve(FCFS).
#include <stdio.h>
#include <stdlib.h>
struct process {
    int pid; // Process ID
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};
int main() {
    int n, i;
    struct process *p;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    p = (struct process *)malloc(n * sizeof(struct process));

    // Input burst times
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    // Calculate waiting time for each process
    p[0].wt = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    // Display results
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    free(p);
    return 0;
}
