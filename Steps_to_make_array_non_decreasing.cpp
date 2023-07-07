#include <bits/stdc++.h>
using namespace std;

int totalSteps(vector<int> &nums)
{
    vector<int> dp(nums.size());
    stack<int> stack;

    for (int i = 0; i < nums.size(); i++)
    {
        int step = 1;
        while (!stack.empty() && nums[stack.top()] <= nums[i])
        {
            step = max(step, dp[stack.top()] + 1);
            stack.pop();
        }
        if (!stack.empty())
        {
            dp[i] = step;
        }
        stack.push(i);
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{

    return 0;
}