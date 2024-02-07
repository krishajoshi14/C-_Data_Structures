#include<iostream>
using namespace std;

struct Process 
{
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
};

int main() 
{
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    cout<<"Enter the number of processes: ";
    cin>>n;
    struct Process p[n], temp;

    // Input the details of each process
    for(i=0; i<n; i++) {
        cout<<"Enter details of process "<<i+1<<endl;
        cout<<"Process Id: ";
        cin>>p[i].pid;
        cout<<"Burst Time: ";
        cin>>p[i].burst_time;
        cout<<"Priority: ";
        cin>>p[i].priority;
        cout<<"Arrival Time: ";
        cin>>p[i].arrival_time;
    }

    // Sort the processes according to their priority
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority < p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int waiting_time[n], turnaround_time[n], completion_time[n];

    // Calculate the completion time, waiting time and turnaround time of each process
    for(i=0; i<n; i++) {
        if(i==0) {
            completion_time[i] = p[i].arrival_time + p[i].burst_time;
        }
        else {
            if(p[i].arrival_time > completion_time[i-1]) {
                completion_time[i] = p[i].arrival_time + p[i].burst_time;
            }
            else {
                completion_time[i] = completion_time[i-1] + p[i].burst_time;
            }
        }
        turnaround_time[i] = completion_time[i] - p[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - p[i].burst_time;
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    cout<<"Process Id\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for(i=0; i<n; i++) 
    {
        cout<<p[i].pid<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].priority<<"\t\t"<<p[i].arrival_time<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnaround_time[i]<<"\t\t"<<completion_time[i]<<endl;
    }

    
    cout<<"Average Waiting Time: "<<avg_waiting_time<<endl;
    cout<<"Average Turnaround Time: "<<avg_turnaround_time<<endl;

    return 0;
}
