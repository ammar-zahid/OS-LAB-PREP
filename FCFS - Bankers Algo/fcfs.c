#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int main()
{
    int allocation[P][R], max[P][R], need[P][R], available[R], work[R];
    bool finish[P] = {false};

    // Input available resources
    printf("Enter available resources: ");
    for (int i = 0; i < R; i++)
        scanf("%d", &available[i]);

    // Input max and allocated resources for each process and calculate need
    for (int i = 0; i < P; i++)
    {
        printf("Enter max and allocated resources for process %d: ", i);
        for (int j = 0; j < R; j++)
        {
            scanf("%d %d", &max[i][j], &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize work with available resources
    for (int i = 0; i < R; i++)
        work[i] = available[i];

    // Banker's Algorithm to check safe state
    while (true)
    {
        bool safe = false;
        for (int i = 0; i < P; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < R; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < R; j++)
                        work[j] += allocation[i][j];
                    finish[i] = true;
                    safe = true;
                }
            }
        }
        if (!safe)
            break; // Exit loop if no allocation was possible
    }

    // Check if all processes are finished
    for (int i = 0; i < P; i++)
    {
        if (!finish[i])
        {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\n");
    return 0;
}