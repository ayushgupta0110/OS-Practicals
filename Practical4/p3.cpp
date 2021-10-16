#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid;
	char ch;

    //fork a child process
    pid = fork();
    if (pid < 0)
    {
	//error occurred 
	cerr<<stderr<<"Fork Failed";
        return 1;
    }
    else if (pid == 0)
    {
	//child process 
	for(int i=0;i<10000;i--)
		cout<<"\nChild Process is running "<<i<<endl;
    }
    else
    {
        //cout<<"\nParent Process."<<endl;
        for(int i=0;i<1000;i++){
        	cout<<"\nParent Process is running";
        	cin>>ch;
        	cin>>ch;
        	cout<<endl;
        	cin>>ch;
        	cin>>ch;
        	}
    }
    return 0;
}

