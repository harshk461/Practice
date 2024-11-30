#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        // Min-heap to store the end times of intervals
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process each interval
        for (auto it : intervals)
        {
            // If the current interval starts after the earliest end time, pop that group
            if (!pq.empty() && pq.top() < it[0])
                pq.pop();

            // Push the end time of the current interval into the heap
            pq.push(it[1]);
        }

        // The size of the heap represents the minimum number of groups
        return pq.size();
    }
};

int main()
{

    return 0;
}