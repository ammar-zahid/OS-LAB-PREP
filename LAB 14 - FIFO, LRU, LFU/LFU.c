#include <stdio.h>

#define FRAME_SIZE 3 // Number of frames

int main()
{
    int pages[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frame[FRAME_SIZE] = {-1, -1, -1}; // Frames initialized as empty
    int count[FRAME_SIZE] = {0}; // Stores frequency of pages in frames
    int pageFaults = 0;

    for (int i = 0; i < 13; i++)
    {
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] == pages[i])
            {
                pageFound = 1; // Page hit
                count[j]++;
                break;
            }
        }

        // If page is not in memory, replace the least frequently used (LFU) page
        if (!pageFound)
        {
            int lfu = 0;
            for (int j = 1; j < FRAME_SIZE; j++)
            {
                if (count[j] < count[lfu])
                {
                    lfu = j; // Find least frequently used page
                }
            }
            frame[lfu] = pages[i]; // Replace LFU page
            count[lfu] = 1;        // Reset frequency count for the new page
            pageFaults++;          // Page fault occurred
        }

        // Print current frame status
        printf("Frame: ");
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults); // Output total page faults
    return 0;
}