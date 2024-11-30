#include <bits/stdc++.h>
using namespace std;

// Speeds up input-output operations by unsyncing C++ and C I/O streams.
// This reduces the time complexity of I/O in competitive programming.
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
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        // DP matrix to store the size of the largest square submatrix ending at each cell
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize the first column of dp matrix with values from the original matrix
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        // Initialize the first row of dp matrix with values from the original matrix
        for (int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];

        // Fill the dp matrix starting from the second row and second column
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // Retrieve values from adjacent cells in the dp matrix
                int count_prev1 = dp[i - 1][j]; // Value directly above
                int prev1 = matrix[i - 1][j];   // Original matrix value directly above

                int count_prev2 = dp[i][j - 1]; // Value to the left
                int prev2 = matrix[i][j - 1];   // Original matrix value to the left

                int count_prev3 = dp[i - 1][j - 1]; // Value diagonally above-left
                int prev3 = matrix[i - 1][j - 1];   // Original matrix value diagonally above-left

                // If current cell and its adjacent cells in the original matrix contain '1's
                // then the cell can contribute to a larger square submatrix.
                if (matrix[i][j] == 1 && (prev1 + prev2 + prev3) == 3)
                    dp[i][j] = 1 + min({count_prev1, count_prev2, count_prev3}); // Extend square submatrix size
                else if (matrix[i][j] == 1 && (prev1 + prev2 + prev3) != 3)
                    dp[i][j]++; // Simply increment if not all neighbors are '1's
            }
        }

        // Calculate the total number of square submatrices by summing up values in dp
        int ans = 0;
        for (auto it : dp)
        {
            for (auto i : it)
                ans += i; // Sum up all dp values which represent squares of different sizes
        }

        return ans; // Total count of square submatrices with all 1's
    }
};

int main()
{

    return 0;
}