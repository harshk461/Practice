#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int mini = INT_MAX;
                for (int k = max(0, col - 1); k < min(n, col + 2); k++)
                    mini = min(mini, matrix[row - 1][k]);
                matrix[row][col] += mini;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};

class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int m = matrix[0].size();
        if (j < 0 || j >= m)
            return 1e9;
        if (i == 0)
            return matrix[0][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + dfs(i - 1, j, matrix, dp);
        int leftDiagonal = matrix[i][j] + dfs(i - 1, j - 1, matrix, dp);
        int rightDiagonal = matrix[i][j] + dfs(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxi = INT_MAX;

        for (int j = 0; j < m; j++)
        {
            int ans = dfs(n - 1, j, matrix, dp);
            maxi = min(maxi, ans);
        }

        return maxi;
    }
};

typedef pair<int, pair<int, int>> pi;
class Solution
{
public:
    vector<pair<int, int>> dirn = {
        {1, -1},
        {1, 0},
        {1, 1}};
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> costs(n, vector<int>(n, INT_MAX));

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({matrix[0][i], {0, i}});
            costs[0][i] = matrix[0][i];
        }

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int i = top.second.first;
            int j = top.second.second;

            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                if (x >= 0 && x < n && y >= 0 && y < n)
                {
                    int new_cost = cost + matrix[x][y];

                    if (new_cost < costs[x][y])
                    {
                        costs[x][y] = new_cost;
                        pq.push({costs[x][y], {x, y}});
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> arr = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    Solution s;
    s.minFallingPathSum(arr);
    return 0;
}