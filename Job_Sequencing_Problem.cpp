#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    bool static comp(Job a, Job b)
    {
        return a.dead < b.dead;
    }
    vector<int> JobScheduling(Job jobs[], int n)
    {
        sort(jobs, jobs + n, comp);
        priority_queue<int, vector<int>, greater<int>> pq;

        int curr = 1; // current deadline

        for (int i = 0; i < n; i++)
        {
            if (jobs[i].dead >= curr)
            {
                pq.push(jobs[i].profit);
                curr++; // increase deadline
            }
            else
            {
                if (jobs[i].profit > pq.top())
                {
                    pq.push(jobs[i].profit);
                    pq.pop();
                }
            }
        }

        int total_profit = 0;
        int num_jobs = pq.size();

        while (!pq.empty())
        {
            total_profit += pq.top();
            pq.pop();
        }

        return {num_jobs, total_profit};
    }
};

int main()
{

    return 0;
}