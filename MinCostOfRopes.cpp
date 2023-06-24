#include <bits/stdc++.h>
using namespace std;

// TC-O(nlogn)
// SC-O(n)
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        // create a min heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        long long cost = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a + b;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};

int main()
{

    return 0;
}