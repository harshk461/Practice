#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<int>> dir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        vector<vector<int>> ans;

        for (auto vec : dir)
        {
            int i = row + vec[0] * 1;
            int j = column + vec[1] * 1;
            if (i < n && j < n && i >= 0 && j >= 0)
                ans.push_back({i, j});
        }

        double Prob = 0.0;
        vector<vector<int>> temp = ans;
        while (k--)
        {
            vector<vector<int>> arr;
            for (auto vec : temp)
            {
                int i = row + vec[0] * 1;
                int j = column + vec[1] * 1;
                if (i < n && j < n && i >= 0 && j >= 0)
                    arr.push_back({i, j});
            }
            Prob += (double)arr.size() / (double)temp.size();
            temp = arr;
        }
        return Prob;
    }
};

class Solution
{
private:
    bool isInside(int x, int y, int n)
    {
        if (x < n && y < n && x >= 0 && y >= 0)
            return true;
        return false;
    }

public:
    double knightProbability(int n, int k, int row, int column)
    {
        double dp[n][n][k + 1];
        vector<vector<int>> dir = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][0] = 1;

        for (int s = 1; s <= k; s++)
        {
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    double prob = 0.0;

                    for (int i = 0; i < 8; i++)
                    {
                        int nx = x + dir[i][0];
                        int ny = y + dir[i][1];

                        if (isInside(nx, ny, n))
                            prob += dp[nx][ny][s - 1] / 8.0;
                    }
                    dp[x][y][s] = prob;
                }
            }
        }
        return dp[row][colums][k];
    }
};

int main()
{
    Solution s;
    cout << s.knightProbability(3, 2, 0, 0);
    return 0;
}