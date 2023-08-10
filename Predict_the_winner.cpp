#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, int start, int end, int turn)
    {
        if (start == end)
            return 0;

        int player1 = 0;
        int player2 = 0;

        // 1->player1
        // 0->player2
        if (turn)
            player1 += max(arr[start] + solve(arr, start + 1, end, 0), arr[end] + solve(arr, start, end - 1, 0));
        else
            player2 += min(arr[start] + solve(arr, start + 1, end, 1), arr[end] + solve(arr, start, end - 1, 1));

        if (player1 > player2)
            return 1;
        return 0;
    }

    int solveMem(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[i][i] = arr[i];

        for (int d = 1; d < n; d++)
            for (int i = 0; i + d < n; i++)
            {
                int j = i + d;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        return dp[0][n - 1] >= 0;
    }

public:
    bool PredictTheWinner(vector<int> &nums)
    {
        return solve(nums, 0, nums.size(), 1);
    }
};

int main()
{

    return 0;
}