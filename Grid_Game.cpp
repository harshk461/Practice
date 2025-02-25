#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        // Calculate the total points in the first row (row1_sum) initially.
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        // Initialize row2_sum to 0, as no points have been collected from the second row yet.
        long long row2_sum = 0;

        // Initialize the answer to a very large value.
        long long ans = LLONG_MAX;

        // Iterate through each column from 0 to n-1.
        for (int i = 0; i < grid[0].size(); i++)
        {
            // The first robot moves to the right, so we subtract the current column's points from row1_sum.
            row1_sum -= grid[0][i];

            // Calculate the maximum points the second robot can collect if it starts from (1, i).
            // The second robot can collect from the remaining right part of the first row or the accumulated points in the second row.
            ans = min(ans, max(row1_sum, row2_sum));

            // The second robot can also move down from the current column, so we add the points from the second row to row2_sum.
            row2_sum += grid[1][i];
        }

        // The final answer is the minimum of the maximum points the second robot can collect for each possible column the first robot can move down to.
        return ans;
    }
};

int main()
{

    return 0;
}