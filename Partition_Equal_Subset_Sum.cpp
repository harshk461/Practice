#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int index, vector<int> &arr, int n, int target)
    {
        // base case
        if (index >= n)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        int include = solve(index + 1, arr, n, target - arr[index]);
        int excl = solve(index + 1, arr, n, target);

        return include or excl;
    }

    bool solveMem(int index, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
    {
        // base case
        if (index >= n)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        if (dp[index][target] != -1)
            return dp[index][target];

        int include = solveMem(index + 1, arr, n, target - arr[index], dp);
        int excl = solvemem(index + 1, arr, n, target, dp);

        return dp[index][target] = include or excl;
    }

    bool solveTab(vector<int> &arr, int n, int t)
    {
        vector<vector<int>> tab(n + 1, vector<int>(t + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= t; target++)
            {
                int include = 0;
                if (target - arr[index] >= 0)
                    include = dp[index + 1][target - arr[index]];
                int excl = dp[index + 1][target];
                dp[index][target] = include or excl;
            }
        }
        return dp[0][t];
    }

public:
    int equalPartition(int N, vector<int> arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total & 1)
            return 0;
        int target = total / 2;
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));
        return solveMem(0, arr, N, target, dp);
    }
};

int main()
{

    return 0;
}