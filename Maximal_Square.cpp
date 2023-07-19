#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursion TLE
    int solveRec(vector<vector<char>> &matrix, int i, int j, int &maxi)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        int right = solve(matrix, i, j + 1);
        int diagonal = solve(matrix, i + 1, j + 1);
        int down = solve(matrix, i + 1, j);

        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else
            return 0;
    }

    // Memoisation
    int solveMem(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMem(matrix, i, j + 1, maxi, dp);
        int diagonal = solveMem(matrix, i + 1, j + 1, maxi, dp);
        int down = solveMem(matrix, i + 1, j, maxi, dp);

        if (matrix[i][j] == '1')
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }

    // tabulation
    int solveTab(vector<vector<char>> &mat)
    {
        int row = matrix.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        int maxi = 0;

        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                int dialgonal = dp[i + 1][j + 1];
                if (mat[i][j] == '1')
                {
                    dp[i][j] = 1 + min(right, min(dialgonal, down));
                    maxi = max(dp[i][j], maxi);
                }

                else
                    dp[i][j] = 0;
            }
        }
        return dp[0][0];
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi * maxi;
    }
};

int main()
{

    return 0;
}