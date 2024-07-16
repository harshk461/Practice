class Solution
{
private:
    int solve(int col, int curr, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (col >= grid[0].size())
            return 0;

        if (dp[col][curr] != -1)
            return dp[col][curr];

        int moves = 0;
        // we want all same value in a column
        //  we try all the values from 1 to 9
        for (int i = 0; i < grid.size(); i++)
            if (grid[i][col] != curr)
                moves++;

        int ans = 1e9;
        // check remaining column by checking all the values
        for (int i = 0; i <= 9; i++)
            // value of next column should not be equal to previous column
            if (i != curr)
                ans = min(ans, moves + solve(col + 1, i, grid, dp));

        return dp[col][curr] = ans;
    }

public:
    int
    minimumOperations(vector<vector<int>> &grid)
    {
        int ans = 1e9;
        int m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(10, -1));
        for (int i = 0; i <= 9; i++)
            ans = min(ans, solve(0, i, grid, dp));

        return ans;
    }
};