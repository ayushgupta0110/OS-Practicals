#include <iostream>
#include <iomanip>
using namespace std;
#define MIN_PRIORITY 100000
class Process
{
    public:
    int burst_time;
    int _PRIORITY_;
    int arrival_time;
    bool is_completed;
    int start_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
    

    /**
     * @param priority Priority number(int)
     * @param b_time Process Burst Time (int)
     * @param arr_time Process arrival time (int)
    */
    Process(int priority, int b_time, int arr_time)
    {
        burst_time       = b_time;
        _PRIORITY_       = priority;
        arrival_time     = arr_time;
        is_completed     = false;
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
        start_time       = *current_time;
        (*current_time) += burst_time;
        completion_time  = (*current_time);
        turn_around_time = completion_time  - arrival_time;
        waiting_time     = turn_around_time - burst_time;
        is_completed     = true;
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
    cout<<"\n"<<setw(65)<<"--NON PREEMPIVE PRIORITY SCHEDULING ALGORITHM--\n\n";
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

void priority_NP(Process ready_queue[],int num_processes)
{
    int current_time = 0;

    for(int current_process=0; current_process<num_processes;)
    {
        int max_priority = MIN_PRIORITY;
        int max_pr_index = -1;
        for(int j=0; j<num_processes; j++)
        {
            if( (!ready_queue[j].is_completed) && (ready_queue[j].arrival_time <= current_time))
            {
                if(ready_queue[j]._PRIORITY_ < max_priority)
                {
                    max_priority = ready_queue[j]._PRIORITY_;
                    max_pr_index = j;
                }
            }
        }

        if(max_pr_index == -1)
        {
            current_time++;
            continue;
        }
        ready_queue[max_pr_index].setInfo(&current_time);
        current_process++;
    }
    process_display(ready_queue,num_processes);
}

int main()
{
    int num_of_process = 4;
    //param: Priority, BurstTime, ArrivalTime
    Process p1(3,6,1);
    Process p2(1,3,3);
    Process p3(4,1,4);
    Process p4(2,7,5);
	// Process p1(3,5,0);
    // Process p2(1,4,1);
    // Process p3(4,2,2);
    // Process p4(2,1,4);

    Process process_array[] = {p1,p2,p3,p4};
    priority_NP(process_array,num_of_process);
}  
