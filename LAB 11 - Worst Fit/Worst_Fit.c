#include <stdio.h>

int main()
{
    int block_size[10], process_size[10], allocation[10];
    int num_blocks, num_processes;

    // Blocks ke number aur unki sizes input karo
    printf("Enter number of blocks: ");
    scanf("%d", &num_blocks);

    for (int i = 0; i < num_blocks; i++)
    {
        printf("Block %d size: ", i + 1);
        scanf("%d", &block_size[i]);
    }

    // Processes ke number aur unki sizes input karo
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d size: ", i + 1);
        scanf("%d", &process_size[i]);
    }

    // Worst-fit allocation
    for (int i = 0; i < num_processes; i++) // Har process ko allocate karo
    {
        int block_index = -1; // Koi block abhi tak allocate nahi hua
        int max_size = 0;     // Sabse bara block track karne k liye

        for (int j = 0; j < num_blocks; j++) // Har block ko check karo
        {
            if (block_size[j] >= process_size[i] && block_size[j] > max_size)
            {
                max_size = block_size[j]; // Sabse bara block size update karo
                block_index = j;          // Block ka index update karo
            }
        }

        allocation[i] = block_index; // Allocate kiye gaye block ka index store karo

        if (block_index != -1) // agar block process ko de diya hai lekin uska size process se bara hai
        {
            block_size[block_index] -= process_size[i]; // Process size ko block size mein se minus kro
        }
    }

    // Results output karo
    printf("\nProcess\tBlock\n");

    for (int i = 0; i < num_processes; i++)
    {
        if (allocation[i] == -1)
        {
            printf("Process %d cannot be allocated\n", i + 1); // Agar block allocate nahi hua
        }
        else
        {
            printf("Process %d <- Block %d\n", i + 1, allocation[i] + 1); // Process aur block allocation dikhana
        }
    }

    return 0;
}
