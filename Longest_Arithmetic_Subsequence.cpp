#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int diff, vector<int> &arr)
    {
        if (index < 0)
            return 0;

        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
            if (arr[index] - arr[j] == diff)
                ans = max(ans, 1 + solve(j, diff, arr));
        return ans;
    }

    int solveMem(int index, int diff, vector<int> &arr, unordered_map<int, int> dp[])
    {
        if (index < 0)
            return 0;

        if (dp[index].count(diff))
            return dp[index][diff];

        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (arr[index] - arr[j] == diff)
                ans = max(ans, 1 + solveMem(j, diff, arr, dp));
        }
        return dp[index][diff] = ans;
    }

    int solveTab(vector<int> arr)
    {
        int n = arr.size();
        if (n <= 2)
            return n;

        int ans = 0;
        unordered_map<int, int> dp[n + 1];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = arr[j] - arr[i];
                int count = 1;

                // check answer is already present
                if (dp[j].count(diff))
                    count = dp[j][diff];
                dp[i][diff] = 1 + count;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }

public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        int ans = 0;
        unordered_map<int, int> dp[n + 1];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
        return ans;
    }
};

int main()
{

    return 0;
}