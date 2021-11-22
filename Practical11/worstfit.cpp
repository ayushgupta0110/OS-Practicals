#include <iostream>
using namespace std;

int main()
{
	int i,j,k,n,m[10],p[10],po[20],flag,z,y,temp,temp1;
	cout<<"enter memory partition:\t";
	cin>>n;
	cout<<"\nenter memory size for\n";
	
	for(i=1;i<=n;i++)
	{
		cout<<"\npartition "<< i<<" :\t";
		cin>>m[i];
		po[i]=i;
	}

	cout<<"\nenter process:\t";
	cin>>j;
	cout<<"\nenter memory size for\n";

	for(i=1;i<=j;i++)
	{
		cout<<"\nprocess "<< i<<" :\t";
		cin>>p[i];
	}
	cout<<"\nworst fit\n\t";
	for(y=1;y<=n;y++)
	{
		for(z=y;z<=n;z++)
		{
			if(m[y] < m[z])
			{
				temp=m[y];
				m[y]=m[z];
				m[z]=temp;
				temp1=po[y];
				po[y]=po[z];
				po[z]=temp1;
			}
		}
	}
	
	for(i=1;i<=j;i++)
	{
		flag=1;
		for(k=1;k<=n;k++)
		{
			if(p[i]<=m[k])
			{
				cout<<"\nprocess "<< i<<" whose memory size is "<< p[i]<<"KB allocated at memory partition:\t"<< po[k];
				m[k]=m[k]-p[i];
				break;
			}
			else
			{
				flag++;
			}
		}
	
		if(flag>n)
		{
			cout<<"\nprocess "<< i<<" whose memory size is "<< p[i]<<"KB can't be allocated";
		}
	}
	return 0;
}
