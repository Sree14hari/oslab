#include <stdio.h>
#include <limits.h>

int main() {
    int n;
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
        rt[i] = bt[i]; 
    }

    int shortest, min_rt;
    int finish_time;
    int check;

    while (completed != n) {
        shortest = -1;
        min_rt = INT_MAX;
        check = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
                check = 1;
            }
        }

        if (check == 0) {
            time++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            completed++;
            finish_time = time + 1;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            total_tat += tat[shortest];
            total_wt += wt[shortest];
        }

        time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
