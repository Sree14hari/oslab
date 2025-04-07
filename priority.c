#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[10], bt[10], at[10], priority[10], ct[10], tat[10], wt[10];
    int completed[10] = {0};
    float total_tat = 0, total_wt = 0;
    int time = 0, count = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        printf("Enter Priority for P%d : ", pid[i]);
        scanf("%d", &priority[i]);
    }

    while (count < n) {
        int idx = -1, min_priority = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !completed[i] && priority[i] < min_priority) {
                min_priority = priority[i];
                idx = i;
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = 1;
            total_tat += tat[idx];
            total_wt += wt[idx];
            count++;
        } else {
            time++; 
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
