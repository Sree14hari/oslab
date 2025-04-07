#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[10], bt[10], ct[10], tat[10], wt[10];
    int completed[10] = {0};
    int time = 0, count = 0;
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    while (count < n) {
        int min_index = -1;
        int min_bt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
        } else {
            time += bt[min_index];
            ct[min_index] = time;
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            completed[min_index] = 1;
            total_tat += tat[min_index];
            total_wt += wt[min_index];
            count++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
