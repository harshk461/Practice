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
    // Function to find the chair assigned to the target friend
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        // Target friend's arrival time
        int target_arrival = times[targetFriend][0];

        // Min heap to store all the available chairs by their index
        // The smallest chair index will be at the top
        priority_queue<int, vector<int>, greater<int>> available_chairs;

        // Min heap to store the reserved chairs as pairs of {leaving time, chair index}
        // The chair that will become available the soonest is at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserved;

        // Sort times by arrival time (so we can process friends in the order they arrive)
        sort(times.begin(), times.end());

        // Process each friend's arrival and departure time
        for (auto time : times)
        {
            int at = time[0]; // Arrival time
            int lt = time[1]; // Leaving time

            // Free up chairs that become available before or at the current friend's arrival time
            while (!reserved.empty() && reserved.top().first <= at)
            {
                // Push the chair back into available chairs as it is free now
                available_chairs.push(reserved.top().second);
                reserved.pop();
            }

            // If the current friend's arrival time is the same as the target friend's
            if (at == target_arrival)
                break; // We will assign a chair to the target friend after this

            // If no chairs are available, assign the next available chair number (new chair)
            if (available_chairs.empty())
                reserved.push({lt, reserved.size()});
            else
            {
                // If a chair is available, assign it to the current friend
                reserved.push({lt, available_chairs.top()});
                available_chairs.pop();
            }
        }

        // Return the chair that would be assigned to the target friend
        // If there are no available chairs, it means we will assign a new chair, so return the size of reserved (the next chair index)
        return available_chairs.empty() ? reserved.size() : available_chairs.top();
    }
};

int main()
{

    return 0;
}