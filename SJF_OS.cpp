#include<iostream>
using namespace std;
int main()
{
    int n,bt[10],p[10],wt[10],ct[10],tat[10],at[10],sum=0,pos,i,j,temp;
    float avg_wt,avg_tat,total_wt=0,total_tat=0;

    cout<<"Enter number of processes: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter arrival time of P"<<i+1<<": ";
        cin>>at[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter burst time of P"<<i+1<<": ";
        cin>>bt[i];
        p[i]=i+1;
    }

    for(i=0;i<n;i++) //Sorting of the burst time and processes
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
            {
                pos=j;
            }
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    for(i=0;i<n;i++)
    {
        sum=sum+bt[i];
        ct[i]=sum;
    }
    wt[0]=0;

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
    }
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
    }

    for(i=0;i<n;i++)
    {
        total_tat=total_tat+tat[i];
    }

    for(i=0;i<n;i++)
    {
        total_wt=total_wt+wt[i];
    }

    cout<<"\nProcess\t Arrival Time\t Burst Time\t Completion Time \tTurnaround Time\t\tWait Time";
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t\t %d\t\t %d\t\t\t %d\t\t %d\t\t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    avg_wt=total_wt/n;
    avg_tat=total_tat/n;

    cout<<"\n\nAverage Waiting Time= "<<avg_wt;
    cout<<"\nAverage Turnaround Time= "<<avg_tat<<endl;

    return 0;
}