#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    // Disable synchronization with C-style I/O and untie cin from cout
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Define a type alias for the priority queue elements
typedef pair<int, pair<int, int>> pi;

class Solution
{
public:
    // Define the possible movement directions (right, left, down, up)
    vector<pair<int, int>> dirn = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Initialize the minimum cost grid with a high value (INT_MAX)
        vector<vector<int>> min_cost(n, vector<int>(m, INT_MAX));

        // Priority queue to process cells in the order of their cost (min heap)
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // Start from the top-left corner with a cost of 0
        min_cost[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first;  // Current row
            int j = top.second.second; // Current column
            int cost = top.first;      // Current cost to reach this cell

            // If this cost is not the minimum cost recorded for this cell, skip processing
            if (min_cost[i][j] != cost)
                continue;

            // Explore all 4 possible directions
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i + dirn[dir].first;  // New row after moving in direction 'dir'
                int y = j + dirn[dir].second; // New column after moving in direction 'dir'

                // Check if the new cell is within the grid bounds
                if (x >= 0 && x < n && y >= 0 && y < m)
                {
                    // Calculate the new cost to reach the neighboring cell
                    // If the direction does not match the grid's indication, add an extra cost of 1
                    int new_cost = cost + (dir != (grid[i][j] - 1) ? 1 : 0);

                    // If this new cost is less than the previously recorded cost for the cell
                    if (min_cost[x][y] > new_cost)
                    {
                        // Update the minimum cost and add the cell to the priority queue
                        min_cost[x][y] = new_cost;
                        pq.push({new_cost, {x, y}});
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return min_cost[n - 1][m - 1];
    }
};

int main()
{

    return 0;
}