#include <stdio.h>

int main()
{
    int block_size[10], process_size[10], allocation[10];
    int num_blocks, num_processes;

    // Input number of blocks and their sizes
    printf("Enter number of blocks: ");
    scanf("%d", &num_blocks);

    for (int i = 0; i < num_blocks; i++)
    {
        printf("Block %d size: ", i + 1);
        scanf("%d", &block_size[i]);
    }

    // Input number of processes and their sizes
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d size: ", i + 1);
        scanf("%d", &process_size[i]);
    }

    // Worst-fit allocation
    for (int i = 0; i < num_processes; i++) // Loop through each process
    {                         
        int worst_index = -1; // no block allocated yet
        int max_size = 0;     // To keep track of the largest block size found

        for (int j = 0; j < num_blocks; j++) // Loop through each block
        { 
            // Check if the block can fit the process and is larger than the current max
            if (block_size[j] >= process_size[i] && block_size[j] > max_size)
            {
                max_size = block_size[j]; // Update the largest block size
                worst_index = j;          // Update the index of the largest block
            }
        }

        allocation[i] = worst_index; // Store the index of the allocated block

        // If a suitable block was found, reduce its size
        if (worst_index != -1)
        {
            block_size[worst_index] -= process_size[i]; // Decrease block size
        }
    }

    // Output results
    printf("\nProcess\tBlock\n");

    for (int i = 0; i < num_processes; i++)
    {
        if (allocation[i] == -1)
        {
            printf("Process %d cannot be allocated\n", i + 1);
        }
        else
        {
            printf("Process %d <- Block %d\n", i + 1, allocation[i] + 1);
        }
    }

    return 0;
}