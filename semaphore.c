#include <stdio.h>

int mutex = 1;      // Semaphore
int full = 0;       // Items produced
int empty = 3;      // Space in buffer (assume size 3)
int item = 0;       // Item count

void wait() {
    mutex--;
}

void signal() {
    mutex++;
}

void produce() {
    wait();
    empty--;
    full++;
    item++;
    printf("Produced item %d\n", item);
    signal();
}

void consume() {
    wait();
    full--;
    empty++;
    printf("Consumed item %d\n", item);
    item--;
    signal();
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            if(mutex == 1 && empty != 0)
                produce();
            else
                printf("Buffer is Full!\n");
        } else if(choice == 2) {
            if(mutex == 1 && full != 0)
                consume();
            else
                printf("Buffer is Empty!\n");
        } else {
            break;
        }
    }
    return 0;
}
