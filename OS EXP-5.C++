#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], priority[20], waiting[20], turnaround[20], process[20], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d (Burst Priority): ", i+1);
        scanf("%d %d", &burst[i], &priority[i]);
        process[i] = i+1;  // process ID
    }

    
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (priority[i] > priority[j]) {
                // swap priority
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                // swap burst
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
                // swap process id
                temp = process[i]; process[i] = process[j]; process[j] = temp;
            }
        }
    }

    // Waiting time
    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
        avg_wt += waiting[i];
    }

    // Turnaround time
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        avg_tat += turnaround[i];
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", process[i], burst[i], priority[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}

