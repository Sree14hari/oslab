#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[100], n, i, j, head, seek = 0, temp;
    int direction;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Add the head to the request list
    request[n++] = head;

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    // Find the position of the head
    int pos;
    for (i = 0; i < n; i++) {
        if (request[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence:\n");

    if (direction == 1) { // right
        for (i = pos; i < n; i++) {
            printf("%d -> ", request[i]);
            seek += abs(head - request[i]);
            head = request[i];
        }
        for (i = pos - 1; i >= 0; i--) {
            printf("%d -> ", request[i]);
            seek += abs(head - request[i]);
            head = request[i];
        }
    } else { // left
        for (i = pos; i >= 0; i--) {
            printf("%d -> ", request[i]);
            seek += abs(head - request[i]);
            head = request[i];
        }
        for (i = pos + 1; i < n; i++) {
            printf("%d -> ", request[i]);
            seek += abs(head - request[i]);
            head = request[i];
        }
    }

    printf("End\n");
    printf("\nTotal Seek Time: %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / (n - 1));

    return 0;
}
