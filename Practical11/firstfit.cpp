#include <iostream>
using namespace std;

struct job
{
	int no;
	int size;
	int add;
};

struct mem
{
	int no;
	int size;
	int f;
	int jno;
};

int main()
{
	cout<<"\n Enter No of Blocks in memory:";
	int loc;
	cin>>loc;
	int x,y;
	mem m[99],tempm;

	for (int i=0; i < loc; i++)
	{
		cout<<"\n Enter Size of block"<< i+1<<":";
		cin>>m[i].size;
		m[i].no=i+1;
		m[i].f=0;
		m[i].jno=0;
	}

	int jobn;
	cout<<"\n Enter No of Jobs:";
	cin>>jobn;
	job j[99];

	for(x=0; x < jobn; x++)
	{
		cout<<"\n Enter size of Job"<< x+1<<":";
		cin>>y;
		j[x].no=x+1;
		j[x].size=y;
		j[x].add=0;
	}

	cout<<"\nJobNo\tJobSize";
	for(x=0; x < jobn; x++)
	{
		cout<<"\n";
		cout<< j[x].no;
		cout<<"\t"<< j[x].size;
	}

	for (x=0; x < jobn; x++)
	{
		for(y=0; y < loc; y++)
		{
			if((m[y].f==0)&&(m[y].size>=j[x].size)&&(j[x].add!=1))
			{
				m[y].jno=j[x].no;
				m[y].f=1;
				j[x].add=1;
			}
		}
	}

	cout<<"\nBlockNo\tMemSize\tJobNo\tJobSize\tStatus\tInternalFreg";
	for(x=0; x < loc; x++)
	{
		cout<<"\n";
		cout<< m[x].no;
		cout<<"\t"<< m[x].size;
		cout<<"\t"<< m[x].jno;
		y=m[x].jno;
		y=y-1;
		if(m[x].jno!=0)
			cout<<"\t"<< j[y].size;
		else
			cout<<"\t"<<"0";

		cout<<"\t"<< m[x].f;

		if(m[x].jno!=0)
			cout<<"\t"<< m[x].size-j[y].size;
		else
			cout<<"\t"<<"0";
	}
	return 0;
}
