#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	pid_t pid;
	
	//creating child process
	pid=fork();

	if(pid<0)
	{
            cout<<"\nNo process entered";
	}
	else if(pid==0)
	{
	     execlp("/bin/ls","ls",NULL);
	     cout<<"\nChild process";
	}
	else
	{
            cout<<"\nParent process\n";
	}
    return 0;
}
