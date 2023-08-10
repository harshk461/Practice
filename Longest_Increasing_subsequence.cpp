#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> &arr, int n, int curr, int prev)
    {
        if (curr == n)
            return 0;

        // include
        int take = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            take = 1 + solve(arr, n, curr + 1, curr);

        // exclude
        int notTake = 0 + solve(arr, n, curr + 1, prev);

        return max(take, notTake);
    }

    int solveMem(vector<int> &arr, int n, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // include
        int take = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            take = 1 + solveMem(arr, n, curr + 1, curr, dp);

        // exclude
        int notTake = 0 + solveMem(arr, n, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int solveTab(int n, int arr[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // include
                int take = 0;
                if (prev == -1 || arr[curr] > arr[prev])
                    take = 1 + dp[curr + 1][curr];

                // exclude
                int notTake = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }

    // DP using Binary search
    int solveOptimal(int n, int a[])
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

public:
    int solveLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1);
    }
};
int main()
{

    return 0;
}