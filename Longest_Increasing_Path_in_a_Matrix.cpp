#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &matrix, int prev, vector<vector<int>> dp)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = dfs(i - 1, j, matrix, matrix[i][j], dp);
        int right = dfs(i + 1, j, matrix, matrix[i][j], dp);
        int top = dfs(i, j - 1, matrix, matrix[i][j], dp);
        int bottom = dfs(i, j + 1, matrix, matrix[i][j], dp);

        return dp[i][j] = max({left, right, top, bottom}) + 1;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j, matrix, -1, dp));

        return ans;
    }
};

int main()
{

    return 0;
}