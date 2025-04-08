#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
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

    printf("\nSeek Sequence (SCAN):\n");
    if (direction == 1) {
        for (int j = i; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != size - 1) {
            total += abs(head - (size - 1));
            head = size - 1;
            printf("%d ", head); // move to 199
        }
        for (int j = i - 1; j >= 0; j--) {
            total += abs(head - req[j]);
            head = req[j];
            printf("%d ", req[j]);
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
            printf("%d ", head); // move to 0
        }
        for (int j = i; j < n; j++) {
            total += abs(head - req[j]);
            head = req[j];
            printf("%d ", req[j]);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);
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

    printf("\nSeek Sequence (C-SCAN):\n");
    if (direction == 1) {
        for (int j = i; j < n; j++) {
            printf("%d ", req[j]);
            total += abs(head - req[j]);
            head = req[j];
        }
        if (head != size - 1) {
            total += abs(head - (size - 1));
            head = size - 1;
            printf("%d ", head); // go to 199
        }

        total += head; // jump to 0
        head = 0;
        printf("%d ", head); // show 0

        for (int j = 0; j < i; j++) {
            total += abs(head - req[j]);
            head = req[j];
            printf("%d ", req[j]);
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
            printf("%d ", head); // move to 0
        }

        total += size - 1;
        head = size - 1;
        printf("%d ", head); // show 199

        for (int j = n - 1; j >= i; j--) {
            total += abs(head - req[j]);
            head = req[j];
            printf("%d ", req[j]);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);
}

int main() {
    int choice, n, head, direction;
    int req[100];

    while (1) {
        printf("\n\n--- Disk Scheduling Menu ---\n");
        printf("1. SCAN\n2. C-SCAN\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter number of requests: ");
        scanf("%d", &n);
        printf("Enter the request sequence: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &req[i]);
        }

        printf("Enter initial head position: ");
        scanf("%d", &head);
        printf("Enter direction (1 for right →, 0 for left ←): ");
        scanf("%d", &direction);

        switch (choice) {
            case 1: scan(req, n, head, direction); break;
            case 2: cscan(req, n, head, direction); break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
