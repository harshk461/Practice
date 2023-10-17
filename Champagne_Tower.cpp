#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double solve(int poured, int row, int glass, vector<vector<int>> &dp)
    {

        if (row < 0 || glass > row || glass < 0)
            return 0.00;

        if (row == 0 && glass == 0)
            return poured;

        if (dp[row][glass] != -1)
            return dp[row][glass];

        double left = (solve(poured, row - 1, glass - 1, dp) - 1) / 2;

        if (left < 0)
            left = 0;

        double right = (solve(poured, row - 1, glass, dp) - 1) / 2;

        if (right < 0)
            right = 0;

        double total = left + right;

        return dp[row][glass] = total;
    }
    double champagneTower(int poured, int query_row, int query_glass)
    {
        return min(1.00, solve(poured, query_row, query_glass, dp));
        vector<vector<double>> arr(102, vector<double>(102));
        arr[0][0] = (double)poured;
        for (int r = 0; r <= query_row; r++)
            for (int c = 0; c <= r; c++)
            {
                double q = (arr[r][c] - 1.0) / 2.0;
                if (q > 0)
                {
                    arr[r + 1][c] += q;
                    arr[r + 1][c + 1] += q;
                }
            }
        return min(1, arr[query_row][query_glass]);
    }
};

int main()
{

    return 0;
}