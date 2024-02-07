#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"\nEnter the number of processes:";
    cin>>n;
    int AT[n],BT[n],WT[n], TAT[n], P[n];
    float AWT=0, ATAT=0;

    for(i=0;i<n;i++)
    {
        cout<<"Enter the arrival time of process "<<i+1<<": ";
        cin>>AT[i];
        cout<<"Enter the burst time of process "<<i+1<<": ";
        cin>>BT[i];

        P[i]=i+1;
    }
    WT[0]=0;
    for(i=0;i<n;i++)
    {
        WT[i]=0;
        for(j=0;j<i;j++)
        {
            WT[i]=WT[i]+BT[j];
        }
    }
    cout<<endl;
    cout<<"Process\t  Burst Time\t Waiting time\t Turn Around Time";
    for(i=0;i<n;i++)
    {
        TAT[i]=BT[i]+WT[i];
        AWT+=WT[i];
        ATAT+=TAT[i];

        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<BT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i];
    }

    AWT/=i;
    ATAT/=i;

    cout<<endl<<endl<<"Average Waiting Time:"<<AWT;
    cout<<endl<<"Avergae Turnaround Time:"<<ATAT<<endl<<endl;

    return 0;
}