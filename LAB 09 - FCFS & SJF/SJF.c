#include <stdio.h>

int main()
{
    int n, burst[10], wait[10] = {0}, turn[10], temp;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Sorting burst times (SJF logic)
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (burst[i] > burst[j]){
                // Swap burst times
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }

    // Calculate waiting times
    for (int i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + burst[i - 1];
    }

    // Calculate turnaround times and display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        turn[i] = wait[i] + burst[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], wait[i], turn[i]);
    }

    return 0;
}