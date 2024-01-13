#include<iostream>
#define max 20
using namespace std;

int main(){
	int n,ct[max],bt[max],at[max],wt[max],tat[max];
	float avg_tat=0,avg_wt=0;
	cout<<"\nEnter no of processes:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\nEnter burst time for p["<<i+1<<"]:";
		cin>>bt[i];
		cout<<"\nEnter arrival time for p["<<i+1<<"]:";
		cin>>at[i];
	}
	ct[0]=at[0];
	for(int i=0;i<n;i++){
		tat[i]=0;
		wt[i]=0;
		ct[i+1]=ct[i]+bt[i];
		tat[i]=ct[i+1]-at[i];
		wt[i]=tat[i]-bt[i];
		avg_wt=avg_wt+wt[i];
		avg_tat=avg_tat+tat[i];
	}
	cout<<"\nGantt chart\n";
	for(int i=0;i<n;i++){
		cout<<" "<<"p"<<i+1<<"|";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ct[i]<<"\t";
	}
	cout<<"\nturn around time for each process";
	for(int i=0;i<n;i++){
		cout<<"\nTurn around time for p["<<i+1<<"] is:"<<tat[i];
	}
	avg_tat=avg_tat/n;
	cout<<"\nwaiting time for each process";
	for(int i=0;i<n;i++){
		cout<<"\nWaiting time for p["<<i+1<<"] is:"<<wt[i];
	}
	avg_wt=avg_wt/n;
	cout<<"\nAverage turn around time is:"<<avg_tat;
	cout<<"\nAverage waiting time is:"<<avg_wt;
	return 0;
}



/*output

Enter no of processes:4
Enter burst time for p[1]:2
Enter arrival time for p[1]:0
Enter burst time for p[2]:3
Enter arrival time for p[2]:1
Enter burst time for p[3]:4
Enter arrival time for p[3]:2
Enter burst time for p[4]:8
Enter arrival time for p[4]:3
Gantt chart
 p1| p2| p3| p4|
0	2	5	9	
turn around time for each process
Turn around time for p[1] is:2
Turn around time for p[2] is:4
Turn around time for p[3] is:7
Turn around time for p[4] is:14
waiting time for each process
Waiting time for p[1] is:0
Waiting time for p[2] is:1
Waiting time for p[3] is:3
Waiting time for p[4] is:6
Average turn around time is:6.75
Average waiting time is:2.5

*/
