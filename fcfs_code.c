#include <stdio.h>

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];
        waiting_time[i] -= arrival_time[i];
    }
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\n\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
    return 0;
}