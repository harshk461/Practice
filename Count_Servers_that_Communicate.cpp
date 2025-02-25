#include <bits/stdc++.h>
using namespace std;

// Optimize input/output for faster execution
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Unsynchronize C++ and C I/O streams
    cin.tie(0);                  // Untie cin from cout to avoid flushing cout every time cin is used
    cout.tie(0);                 // Untie cout for better performance
    return 'c';
}();

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Vectors to store the number of servers in each row and column
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Count the number of servers in each row
        for (int i = 0; i < n; i++)
            row[i] = accumulate(grid[i].begin(), grid[i].end(), 0);

        // Count the number of servers in each column
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += grid[j][i]; // Add servers in the current column across all rows
            }
            col[i] = sum; // Store the column sum
        }

        // Variable to keep track of the count of servers that can communicate
        int count_of_server_which_have_someone = 0;

        // Traverse the grid to check which servers can communicate
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If the current cell has a server (`grid[i][j] == 1`)
                // and either its row or column has more than one server,
                // it can communicate with another server
                if (grid[i][j] && (row[i] > 1 || col[j] > 1))
                    count_of_server_which_have_someone++;
            }
        }

        // Return the total count of servers that can communicate
        return count_of_server_which_have_someone;
    }
};

int main()
{

    return 0;
}