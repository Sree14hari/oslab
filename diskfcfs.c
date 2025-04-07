#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, seek = 0;
    int request[100];

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d -> ", request[i]);
        seek += abs(request[i] - head);
        head = request[i];
    }
    printf("End\n");

    printf("\nTotal Seek Time: %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / n);

    return 0;
}
