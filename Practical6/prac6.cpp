#include <iostream>
using namespace std;

class process
{
    public:
    int art;
	int bt;
	int wt;
	int ta;

	process()
	{
		art=bt=wt=ta=0;
	}
};

int main()
{
    double wta=0,taa=0;
    int n;
    process tmp;
    cout<<"\nEnter the number of Processes: ";
    cin>>n;
    
    //created an array of processes
    process *p=new process[n];
	
	//Taking Arrival Time and Burst Time as Input from the user
	for(int i=0;i<n;i++)
	{
        cout<<"\nEnter the arrival Time for Process "<< i+1 <<": ";
        cin>>p[i].art;
		cout<<"\nEnter the Burst Time for Process "<< i+1 <<": ";
        cin>>p[i].bt;
    }

	for(int i=0; i < n; i++)
	{
        for(int j=i+1; j < n; j++)
		if(p[i].art<=p[j].art)
		{
			p[j].wt=p[i].art+p[i].wt+p[i].bt-p[j].art;
			if(p[j].wt < 0)
            	p[j].wt=0;
		}
		else
		{
            tmp=p[i];
            p[i]=p[j];
            p[j]=tmp;
        }
        p[i].ta=p[i].bt+p[i].wt;
    }

	for(int i=0; i < n; i++)
	{
        wta+=p[i].wt;
        taa+=p[i].ta;
        cout<<"\nThe Waiting Time for Process "<< i+1<<": "<< p[i].wt;
        cout<<"\nThe Turnaround Time for Process "<< i+1<<": "<< p[i].ta;
        cout<<endl;
    }
	cout<<"\n\nAverage Waiting Time: "<< wta/(double)n;
	cout<<"\nAverage Turnaround Time: "<< taa/(double)n<<endl;
	return 0;
}
