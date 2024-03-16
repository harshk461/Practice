#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int dfs(int i, int j, vector<string> &board, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            dp[i][j] = 0;
            return 0;
        }

        if (i < 0 || j < 0 || board[i][j] == 'X')
            return INT_MIN;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = (board[i][j] - '0' + max({dfs(i - 1, j, board, dp), dfs(i - 1, j - 1, board, dp), dfs(i, j - 1, board, dp)}));

        return dp[i][j] = ans % MOD;
    }

    int targetSum(int i, int j, vector<string> &board, int target, vector<vector<vector<int>>> &dp)
    {
        if (i == 0 && j == 0 && target == 0)
            return 1;

        if (i < 0 || j < 0 || board[i][j] == 'X' || target < 0)
            return 0;

        if (dp[i][j][target] != -1)
            return dp[i][j][target];

        int op1 = targetSum(i, j - 1, board, target - (board[i][j] - '0'), dp) % MOD;
        int op2 = targetSum(i - 1, j - 1, board, target - (board[i][j] - '0'), dp) % MOD;
        int op3 = targetSum(i - 1, j, board, target - (board[i][j] - '0'), dp) % MOD;

        return dp[i][j][target] = (op1 + op2 + op3);
    }

public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int m = board.size();
        int n = board[0].size();
        board[0][0] = '0';
        board[m - 1][n - 1] = '0';

        vector<vector<int>> dp1(m, vector<int>(n, -1));

        int maxSum = dfs(m - 1, n - 1, board, dp1);

        int ans = maxSum < 0 ? 0 : maxSum;
        vector<vector<vector<int>>> dp2(105, vector<vector<int>>(105, vector<int>(ans + 1, -1)));
        int path = targetSum(m - 1, n - 1, board, ans, dp2);
        return {ans, path};
    }
};

int main()
{

    return 0;
}