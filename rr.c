#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int completed = 0, time = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // set remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;
    while (completed < n) {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    total_tat += tat[i];
                    total_wt += wt[i];
                    rt[i] = 0;
                    completed++;
                }
            } else if (at[i] > time) {
                time++; // CPU idle
                break;
            }
        }

        if (done) break;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
