#include <stdio.h>

#define FRAME_SIZE 3 // Number of memory frames

int main()
{
    int pages[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int frames[FRAME_SIZE];
    int pageFaults = 0;
    int nextFramePos = 0; // Tracks the frame position to replace

    // Initialize frames as empty
    for (int i = 0; i < FRAME_SIZE; i++)
    {
        frames[i] = -1;
    }

    // Process each page request
    for (int i = 0; i < 13; i++)
    {
        int pageFound = 0; // Check if the page is already loaded (hit)

        // Check if the page is in any frame
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frames[j] == pages[i])
            {
                pageFound = 1;
                break;
            }
        }

        // If the page is not found, replace it (page fault)
        if (!pageFound)
        {
            frames[nextFramePos] = pages[i];
            nextFramePos = (nextFramePos + 1) % FRAME_SIZE; // Circular replacement
            pageFaults++;
        }

        // Display current frames
        printf("Frame: ");
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    // Output total page faults
    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}