#include <stdio.h>

#define FRAME_SIZE 3 // Defines the size of the frame

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]); // Total number of pages
    int frame[FRAME_SIZE] = {-1, -1, -1};  // Initialize frames as empty
    int pageFaults = 0;

    // Loop through each page in the sequence
    for (int i = 0; i < n; i++)
    {
        int pageFound = 0; // check if the page is already in the frame

        // Check if the current page is already in any frame (page hit)
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] == pages[i])
            {
                pageFound = 1; // Page hit, no replacement needed
                break;
            }
        }

        // If the page is not found, we need to replace it (page fault)
        if (!pageFound)
        {
            int lruIndex = 0; // Variable to track the index of the least recently used page

            // identify the least recently used page
            for (int j = 1; j < FRAME_SIZE; j++)
            {
                if (frame[j] == -1 || frame[lruIndex] == pages[i - 1])
                {
                    lruIndex = j; // Empty frame or LRU page to be replaced
                }
            }

            // Replace the LRU page with the current page
            frame[lruIndex] = pages[i];
            pageFaults++; // Increment the page fault counter
        }

        // Print the current state of the frame after each page access
        printf("Frame: ");
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frame[j] != -1)
                printf("%d ", frame[j]); // Print the pages loaded in the frame
        }
        printf("\n");
    }

    // Output the total number of page faults
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}