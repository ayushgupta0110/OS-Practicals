#include<iostream>
#include<climits>
#include<iomanip>
using namespace std;


class Process{
	public:
	int id;
	int at;
	int bt;
	int wt;
	int tat;
};

void execute_process(Process *p,int n)
{
	int rt[n];// to store remaining time
	int completed=0;// to store no of completed process
	int t=1; //time

	// Assigning remaining time rt[i]=p[i].bt burst times
	for(int i=0;i<n;i++)
		rt[i]=p[i].bt;

	cout<<"\n\t\t Gantt Chart"<<endl;
	cout.setf(ios::left);
	cout<<setw(5)<<"Time"<<"Process"<<endl;

	int shortest=-1,min_rt=INT_MAX;
	while(completed!=n)
	{
		/*to pick the shortest remaining time
		  Process from process with arival time
		  upto time t
		*/


		/* -1 value will help in knowing whether the cpu
			has any process to execute*/

		for(int i=0;i<n;i++)
		{
			if(rt[i]>0 && p[i].at<t && rt[i]<min_rt)
			{
				shortest = i;
				min_rt = rt[i];
			}
		}

		if(shortest==-1)
		{
			cout<<setw(5)<<t<<"idle"<<endl;
			t++;
			continue;
		}
		// this means we have a process to execute
		rt[shortest]--;
		min_rt=rt[shortest];

		cout<<setw(5)<<t<<"P["<<p[shortest].id<<"]"<<endl;

		if(rt[shortest]==0)
		{
			completed++;
			p[shortest].wt = t - p[shortest].at - p[shortest].bt;
			// wait_time = completion_time - arival_time - burst_time

			shortest = -1;
			min_rt = INT_MAX;
		}

		t++;
	}
}

int main()
{
	cout<<"\n\t\tImplementation of Shortest Remaining Time First"<<endl;
	int n; //total no. of Processes
	cout<<"\nEnter the no of processes : ";cin>>n;
	Process p[n];

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Details of process "<<i+1<<" :"<<endl;
		p[i].id=i+1;
		cout<<"Enter Arival Time : ";cin>>p[i].at;
		cout<<"Enter Burst Time : ";cin>>p[i].bt;
	}

	//to calculate wait_time and also printing the Gantt Chart
	execute_process(p,n);

	//to calculate turnaround_time
	for(int i=0;i<n;i++)
	{
		p[i].tat = p[i].wt + p[i].bt;
	}

	//to calculate average turnaround_time and average waiting time
	int total_tat=0,total_wt=0;
	for(int i=0;i<n;i++)
	{
		total_tat += p[i].tat;
		total_wt += p[i].wt;
	}

	//printing the details
	cout<<"\n\n";
	cout<<setw(5)<<"PID"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"WT"<<setw(5)<<"TAT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"P["<<p[i].id<<"] "<<setw(5)<<p[i].at<<setw(5)<<p[i].bt<<setw(5)<<p[i].wt<<setw(5)<<p[i].tat<<endl;
	}
	cout<<endl;
	cout<<"Average Waiting Time : "<<(double) total_wt/n<<endl;
	cout<<"Average Turnaround Time : "<<(double) total_tat/n<<endl;
	cout<<endl;
return 0;
}
