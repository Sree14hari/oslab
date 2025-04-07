#include <stdio.h>

int main() {
    int n, i;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    double total_tat = 0, total_wt = 0; // use double instead of float for better precision

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int t = at[j]; 
                at[j] = at[j + 1]; 
                at[j + 1] = t;
                t = bt[j]; bt[j] = bt[j + 1]; 
                bt[j + 1] = t;
            }
        }
    }

    
    ct[0] = at[0] + bt[0];
    for (i = 1; i < n; i++) {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2lf", total_tat / n);
    printf("\nAverage Waiting Time: %.2lf\n", total_wt / n);

    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++) {
        printf("  P%d  |", i + 1);
    }

    printf("\n%d", at[0]);
    for (i = 0; i < n; i++) {
        printf("    %d", ct[i]);
    }
    printf("\n");

    return 0;
}
