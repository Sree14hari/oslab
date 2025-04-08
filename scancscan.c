#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

void scan(int req[], int n, int head, int direction) {
    int total = 0;
    int size = 200;
    sort(req, n);

    int i;
    for (i = 0; i < n; i++) {
        if (req[i] >= head)
            break;
    }

    printf("\nSeek Sequence:\n");
    if (direction == 1) {
        for (int j = i; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != size - 1) {
            total += abs(head - (size - 1));
            head = size - 1;
        }
        for (int j = i - 1; j >= 0; j--) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
    } else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != 0) {
            total += abs(head - 0);
            head = 0;
        }
        for (int j = i; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
    }

    printf("\nTotal Head Movement: %d\n", total);
}

void cscan(int req[], int n, int head, int direction) {
    int total = 0;
    int size = 200;
    sort(req, n);

    int i;
    for (i = 0; i < n; i++) {
        if (req[i] >= head)
            break;
    }

    printf("\nSeek Sequence:\n");
    if (direction == 1) {
        for (int j = i; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != size - 1) {
            total += abs(head - (size - 1));
            head = size - 1;
        }
        total += size - 1; 
        head = 0;
        for (int j = 0; j < i; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
    } else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != 0) {
            total += abs(head - 0);
            head = 0;
        }
        total += size - 1; 
        head = size - 1;
        for (int j = n - 1; j >= i; j--) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
    }

    printf("\nTotal Head Movement: %d\n", total);
}

int main() {
    int choice, n, head, direction;
    int req[100];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    do {
        printf("\n--- Disk Scheduling Menu ---\n");
        printf("1. SCAN\n2. C-SCAN\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Enter direction (1 for High, 0 for Low): ");
            scanf("%d", &direction);
        }

        switch (choice) {
            case 1:
                scan(req, n, head, direction);
                break;
            case 2:
                cscan(req, n, head, direction);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
