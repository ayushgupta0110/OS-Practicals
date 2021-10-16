/*Round Robin Scheduling Algorithm*/
/*Round robin is a pre-emptive algorithm*/
#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;
#define TIME_QUANTUM 2

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
    int remaining_burst;

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
        remaining_burst  = burst_time;
    }

    /**
     * @brief after process is executed by CPU, set Values for the given process
     * @current_time pointer to the current_time elapsed
     * (pointer is required because we will update the value of current time at the end)
    */
    void setInfo(int *current_time)
    {
        if(remaining_burst == burst_time)
        {
            start_time = (*current_time);
        }

        remaining_burst--;
        (*current_time)+=1;
        // cout<<"+++++  "<<remaining_burst<<" "<<arrival_time<<endl;
        if(remaining_burst==0)
        {
            _is_completed    = true;
            completion_time  = (*current_time);
            turn_around_time = completion_time  - arrival_time;
            waiting_time     = turn_around_time - burst_time;
            cout<<"------+  "<<completion_time<<endl;
        }
    }
};

inline float avgT(deque<Process> arr,int n)
{
    float avg = 0;
    for(int i=0; i<n; i++)
        avg += arr[i].turn_around_time;
    return (avg/n);
}

inline float avgW(deque<Process> arr,int n)
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
void process_display(deque<Process> ready_queue, int num_processes)
{
    cout<<"\n"<<setw(65)<<"--RR SCHEDULING ALGORITHM--\n\n";
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

/**
 * @brief sort processes according to their arrival time
 * @param ready_queue array of processes
 * @param num_processes number of processes
*/
void sort_process_sequence(deque<Process> ready_queue,int num_processes)
{
    for(int i=num_processes;i>0;i--)
    {
        for(int j=0; j<i-1;j++)
        {
            if( ready_queue[j].arrival_time == ready_queue[j+1].arrival_time )
            {
                if( ready_queue[j]._PID_ > ready_queue[j+1]._PID_)
                    swap(ready_queue[j],ready_queue[j+1]);
            }

            else if ( ready_queue[j].arrival_time > ready_queue[j+1].arrival_time )
                swap(ready_queue[j],ready_queue[j+1]);
        }
    }
}

void RR_scheduler(deque<Process> ready_queue,int num_processes)
{
    /*Sort ready_queue according to arrival time (& PID)*/
    sort_process_sequence(ready_queue,num_processes);
    int current_time = 0;
    deque<Process*> schedule_queue;
    int processes_left = num_processes;
    int process_schedule_counter=0;
    while(processes_left)
    {
        if(!schedule_queue.empty())
        {
            if( schedule_queue.at(0)->_is_completed)
            {
                schedule_queue.pop_front();
            }
            else
            {
                Process *temp = schedule_queue[0];
                schedule_queue.pop_front();
                schedule_queue.push_back(temp);
            }
        }

        for(int j=0;j<TIME_QUANTUM;j++)
        {
            // for(int i=0; i<num_processes; i++)
            // {
            //     // cout<<ready_queue[i].arrival_time<<" "<<current_time<<endl;
            //     if((ready_queue[i].arrival_time == current_time) && (!ready_queue[i]._is_completed))
            //     {
            //         schedule_queue.push_back(&ready_queue[i]);
            //     }
            // }

            while(true)
            {
                if((ready_queue[process_schedule_counter].arrival_time == current_time) && (!ready_queue[process_schedule_counter]._is_completed))
                {
                    schedule_queue.push_back(&ready_queue[process_schedule_counter]);
                    process_schedule_counter++;
                }
                else break;
            }
            if (!schedule_queue.empty())
            {
                schedule_queue.at(0)->setInfo(&current_time);

                if (schedule_queue.at(0)->_is_completed)
                {
                    // schedule_queue.pop_front();
                    processes_left--;
                    break;

                }
            }
            else
            {
                j--;
                current_time++;
            }

            while(true)
            {
                if((ready_queue[process_schedule_counter].arrival_time == current_time) && (!ready_queue[process_schedule_counter]._is_completed))
                {
                    schedule_queue.push_back(&ready_queue[process_schedule_counter]);
                    process_schedule_counter++;
                }
                else break;
            }

        }
    }
    process_display(ready_queue,num_processes);
}

int main()
{
    int num_of_process = 4;
    //param: PID, BurstTime, ArrivalTime
    //Dont forget to change to Time Quantum according to problem statement
    Process p1(1,5,0);
    Process p2(2,4,1);
    Process p3(3,2,2);
    Process p4(4,1,4);
    // Process p1(1,6,1);
    // Process p2(2,3,3);
    // Process p3(3,1,4);
    // Process p4(6,7,5); //set TQ to 4
    deque<Process> process_array({p1,p2,p3,p4});
    RR_scheduler(process_array,num_of_process);
