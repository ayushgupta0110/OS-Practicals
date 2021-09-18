#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid;
	
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
	execlp("/bin/ls","ls",NULL);
    }
    else
    {
        cout<<"\nParent Process."<<endl;
    }
    return 0;
}

