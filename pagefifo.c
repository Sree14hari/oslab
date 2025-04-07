#include <stdio.h>

int main() {
    int frames, pages, i, j, k, page_faults = 0;
    int memory[10], page[30], front = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &pages);
    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        memory[i] = -1; 
    }

    printf("\nPage\tFrames\n");
    for (i = 0; i < pages; i++) {
        flag = 0;

        
        for (j = 0; j < frames; j++) {
            if (memory[j] == page[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
           
            memory[front] = page[i];
            front = (front + 1) % frames;
            page_faults++;
        }

        printf("%d\t", page[i]);
        for (k = 0; k < frames; k++) {
            if (memory[k] != -1)
                printf("%d ", memory[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
