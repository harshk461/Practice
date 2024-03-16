#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, vector<vector<int>> &arr, vector<int> &start, vector<int> &dp)
    {
        int n = arr.size();
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // just end se phele wali index
        int next_index = lower_bound(start.begin(), start.end(), arr[i][1]) - start.begin();
        int pick = arr[i][2] + solve(next_index, arr, start, dp);
        int notPick = solve(i + 1, arr, start, dp);

        return dp[i] = max(pick, notPick);
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        // job scheduling array=>(start,end,profit)
        vector<int> dp(n, -1);
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({startTime[i], endTime[i], profit[i]});

        sort(arr.begin(), arr.end(), [&](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        sort(startTime.begin(), startTime.end());

        return solve(0, arr, startTime, dp);
    }
};

int main()
{
    vector<int> a1 = {1, 2, 3, 3};
    vector<int> a2 = {3, 4, 5, 6};
    vector<int> a3 = {50, 10, 40, 70};

    Solution s;
    s.jobScheduling(a1, a2, a3);
    return 0;
}