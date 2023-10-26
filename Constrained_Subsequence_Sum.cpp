#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums, int k)
    {
        int ans = nums[0];
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] += !dq.empty() ? dq.front() : 0;
            ans = max(ans, nums[i]);

            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            if (nums[i] > 0)
                dq.push_back(nums[i]);

            if (i >= k && !dq.empty() && dq.front() == nums[i - k])
                dq.pop_front();
        }
        return ans;
    }

public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            while (!pq.empty())
            {
                auto p = pq.top();
                if (i - p.second > k)
                    pq.pop();
                else
                    break;
            }

            dp[i] = max(nums[i], nums[i] + pq.top().first);
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        return ans;
    }
};

int main()
{

    return 0;
}