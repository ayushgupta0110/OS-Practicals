#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{	
	int ch;
	int mem;
	char choice;
	do{
		cout<<"\n1.Print Kernel version";
		cout<<"\n2.Print CPU info";
		cout<<"\n3.Print Memory info";
		cout<<"\nEnter your choice : ";	
		cin>>ch;
		
		switch(ch){
			
			case 1: cout<<"\nKernel version\n";
				system("cat /proc/version|awk '{print $1,$2, $3}'");
				break;
			case 2: 
				cout<<"\nCPU Type:\n";			
				system("cat /proc/cpuinfo|awk 'NR==3'");
				system("cat /proc/cpuinfo|awk 'NR==8'");
				system("cat /proc/cpuinfo|awk 'NR==13'");
				cout<<"\nCPU Model:\n";
				system("cat /proc/cpuinfo|awk 'NR==5'|awk ' {print $4,$5,$6,$8,$9}'");
				break;
			case 3: cout<<"\nConfigured Memory :\n  ";
				system("cat /proc/meminfo|awk 'NR==1'|awk '{print $2,$3}'");
				cout<<"\nFree Memory :\n  ";
				system("cat /proc/meminfo|awk 'NR==2'|awk ' {print $2,$3}'");
	 			break;
	 		default: cout<<"\nEnter a valid choice!!";
	 	}			
		cout<<"\nTo continue press y or Y, anyother key to exit: ";
		cin>>choice;
	}while(choice=='y' || ch=='Y');
return 0;
}
