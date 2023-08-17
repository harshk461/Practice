#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> ans;

    void solve(int i, int prev, vector<int> &nums, vector<int> &temp, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            if (temp.size() > ans.size())
                ans = temp;
            return;
        }

        // include
        if (temp.size() > dp[i] && nums[i] % prev == 0)
        {
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            solve(i + 1, nums[i], nums, temp, dp);
            temp.pop_back();
        }

        // not include
        solve(i + 1, prev, nums, temp, dp);
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        int n = nums.size();
        vector<int> dp(n, -1);
        solve(0, 1, nums, temp, dp);
        return ans;
    }
};

int main()
{

    return 0;
}