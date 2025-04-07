#include <stdio.h>

int nb, np;
int b[10], p[10], frag[10], alloc[10];

void reset(int original[]) {
    for (int i = 0; i < nb; i++)
        b[i] = original[i];
    for (int i = 0; i < np; i++)
        alloc[i] = -1;
}

void firstFit() {
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                alloc[i] = j;
                frag[i] = b[j] - p[i];
                b[j] = -1;
                break;
            }
        }
    }
}

void bestFit() {
    for (int i = 0; i < np; i++) {
        int best = -1;
        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (best == -1 || b[j] < b[best])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            frag[i] = b[best] - p[i];
            b[best] = -1;
        }
    }
}

void worstFit() {
    for (int i = 0; i < np; i++) {
        int worst = -1;
        for (int j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (worst == -1 || b[j] > b[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            alloc[i] = worst;
            frag[i] = b[worst] - p[i];
            b[worst] = -1;
        }
    }
}

void display() {
    printf("\nProcess\tSize\tBlock\tFragment\n");
    for (int i = 0; i < np; i++) {
        if (alloc[i] != -1)
            printf("P%d\t%d\t%d\t%d\n", i + 1, p[i], alloc[i] + 1, frag[i]);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
    }
}

int main() {
    int original[10], choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter size of each memory block:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
        original[i] = b[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter size of each process:\n");
    for (int i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i]);
    }

    while (1) {
        printf("\nMEMORY ALLOCATION MENU\n");
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        reset(original);

        switch (choice) {
            case 1:
                firstFit();
                display();
                break;
            case 2:
                bestFit();
                display();
                break;
            case 3:
                worstFit();
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
