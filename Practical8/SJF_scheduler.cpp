#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_BURST_TIME 10000

class Process
{
    public:
    int burst_time;
    int _PID_;
    int arrival_time;
    bool _is_completed;
    int start_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;

    /**
     * @param pid Process ID (int)
     * @param b_time Process Burst Time (int)
     * @param arr_time Process arrival time (int)
    */
    Process(int pid, int b_time, int arr_time)
    {
        burst_time       = b_time;
        _PID_            = pid;
        arrival_time     = arr_time;
        _is_completed    = false;
        start_time       = 0;
        completion_time  = 0;
        waiting_time     = 0;
        turn_around_time = 0;
    }
    
    /**
     * @brief after process is executed by CPU, set Values for the given process
     * @current_time pointer to the current_time elapsed
     * (pointer is required because we will update the value of current time at the end)
    */
    void setInfo(int *current_time)
    {
        start_time       = (*current_time);
        _is_completed    = true;
        completion_time  = start_time + burst_time;
        turn_around_time = completion_time  - arrival_time;
        waiting_time     = turn_around_time - burst_time;
        (*current_time) += burst_time;
    }
};

inline float avgT(Process arr[],int n)
{
    float avg = 0;
    for(int i=0; i<n; i++)
        avg += arr[i].turn_around_time;
    return (avg/n);
}

inline float avgW(Process arr[],int n)
{
    float avg = 0;
    for(int i=0; i<n; i++)
        avg += arr[i].waiting_time;
    return (avg/n);
}

/**
 * @brief display processes with their info
 * @param ready_queue array of ready processes 
 * @param num_proceseses number of processes in queue
*/
void process_display(Process ready_queue[], int num_processes)
{
    cout<<"\n"<<setw(65)<<"--SJF SCHEDULING ALGORITHM--\n\n";
    cout<<"\nProcesses\t\tCompletion Time\t\tTurn Around Time\tWaiting Time\n\n";
    for(int i=0; i<num_processes; i++)
    {
        cout<<setw(5)<<"P"<<i+1<<setw(25)<<ready_queue[i].completion_time
            <<setw(25)<<ready_queue[i].turn_around_time<<setw(21)<<ready_queue[i].waiting_time;
        cout<<endl;
    }
    cout<<endl;
	cout<<"Average"<<setw(25)<<"----"<<setw(25)<<avgT(ready_queue,num_processes)
        <<setw(20)<<avgW(ready_queue,num_processes);
    cout<<endl;
}

void SJF_scheduler(Process ready_queue[],int num_processes)
{
    int current_time = 0;
    int processes_left = num_processes;
    
    while(processes_left)
    {
        int min_burst_time_index = 0;
        int min_burst_time = MAX_BURST_TIME;
        //At starting we are assigning a very large burst time value for making comparison easy
        bool process_present = false;
        
        for(int i=0; i<num_processes; i++)
        {
            //if the process is currently present in the queue only then we will proceed
            if(ready_queue[i].arrival_time <= current_time)
            {
                //If There is tie in Shortest Burst Time, we will use FCFS to break tie
				if ( !ready_queue[i]._is_completed && (ready_queue[i].burst_time == min_burst_time) )
                {
					process_present = true;
					if(ready_queue[i].arrival_time < ready_queue[min_burst_time_index].arrival_time)
					{
						min_burst_time_index = i;
						min_burst_time = ready_queue[i].burst_time;
					}
					
					else if(ready_queue[i].arrival_time == ready_queue[min_burst_time_index].arrival_time)
					{
					    //Breaking Tie with PID in case of same arrival_time
						if(ready_queue[i]._PID_ < ready_queue[min_burst_time_index]._PID_)
						{
							min_burst_time_index = i;
							min_burst_time = ready_queue[i].burst_time;
						}
					}
                }
				
				//shortest Job will get priority
				else if ( !ready_queue[i]._is_completed && (ready_queue[i].burst_time < min_burst_time) )
				{
					min_burst_time_index = i;
					process_present = true;
					min_burst_time = ready_queue[i].burst_time;
				}
            }
        }

        if(process_present)
        {
            ready_queue[min_burst_time_index].setInfo(&current_time);
            processes_left--;
            //after completion of process, we will decrease num of processes present
        }
        
        else current_time++;
        /*If at current_time no process is present, we will proceed ahead and then again check 
        if now process is available or not*/
    }
    process_display(ready_queue,num_processes);
}

int main()
{
    int num_of_process = 4;
    //param: PID, BurstTime, ArrivalTime

	Process p1(1,5,0);
    Process p2(2,4,1);
    Process p3(3,2,2);
    Process p4(4,1,4);

    Process process_array[] = {p1,p2,p3,p4};
    SJF_scheduler(process_array,num_of_process);
}  
