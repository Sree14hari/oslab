#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[100], n, i, j, head, seek = 0, temp;
    int disk_size;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    request[n++] = head;
    request[n++] = 0;
    request[n++] = disk_size - 1;

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
    for (i = pos; i < n; i++) {
        printf("%d -> ", request[i]);
        seek += abs(head - request[i]);
        head = request[i];
    }

    // Jump to beginning
    seek += abs(head - request[0]);
    head = request[0];

    for (i = 1; i < pos; i++) {
        printf("%d -> ", request[i]);
        seek += abs(head - request[i]);
        head = request[i];
    }

    printf("End\n");
    printf("\nTotal Seek Time: %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / (n - 3)); 

    return 0;
}
