#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    int id, deadline, profit;

    Job(int id, int deadline, int profit) {
        this -> id = id;
        this -> deadline = deadline;
        this -> profit = profit;
    }
};


class JobSequencing {
public:
    vector<int> JobScheduling(vector<Job>& array) { 
        
        int N = array.size();
        int max_deadline = 0;
        int count_jobs = 0, job_profit = 0;
        
        sort(array.begin(), array.end(), [](Job a, Job b) {
           
           return a.profit > b.profit; 
        });
        
        for (int i = 0; i < N; i++)
            max_deadline = max(max_deadline, array[i].deadline);
            
        
        vector<int> slots(max_deadline + 1, -1);
        
        for (int i = 0; i < N; i++)
        {
            int deadline = array[i].deadline;
            int profit = array[i].profit;
            
            for (int j = deadline; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = i;
                    count_jobs ++;
                    
                    job_profit += profit;
                    break;
                }
            }
        }
        
        return {count_jobs, job_profit};
    } 
};

int main(void) {

    vector<Job> array {Job(1, 4, 20), Job(2, 1, 10), Job(3, 1, 40), Job(4, 1, 30)};

    JobSequencing solution;
    vector<int> output = solution.JobScheduling(array);

    int total_numbers_of_jobs_done = output[0];
    int maximum_profit = output[1];

    cout << "Total number of jobs done : " << total_numbers_of_jobs_done << endl;
    cout << "Maximum Profit : " << maximum_profit ; 

    return 0;
}