#include <stdio.h>

int main() {
    int burst[20], wait[20] = {0}, turn[20], n;
    float avgWait = 0, avgTurn = 0;

    // Input number of processes and burst times
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Calculate waiting and turnaround times
    for (int i = 1; i < n; i++){ 
        wait[i] = wait[i-1] + burst[i-1]; //wait[i-1]->wait time of previous process
    }

    for (int i = 0; i < n; i++) {
        turn[i] = wait[i] + burst[i];
        avgWait += wait[i]; //add all waiting times
        avgTurn += turn[i]; //add all turnaround times
    }

    // Output results
    printf("\nProcess\tBurst\tWait\tTurnaround\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], wait[i], turn[i]);

    printf("Avg Wait: %.2f\nAvg Turnaround: %.2f\n", avgWait/n, avgTurn/n);

    return 0;
}