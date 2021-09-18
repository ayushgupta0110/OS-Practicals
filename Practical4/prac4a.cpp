#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid,p;
    
    //creating a child process
    p=fork();
    
    //function to get id of the process
    pid=getpid();
	if(p < 0)
	{
        cerr<<endl<<stderr<<"Fork Failed";
		return 1;
	}
    cout<<"\nOutput of Fork id: "<<p;
    cout<<"\nProcess id is: "<<pid<<endl;
    return 0;
}
