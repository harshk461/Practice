#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

typedef pair<int, pair<int, int>> pi;

class Solution
{
private:
    vector<pair<int, int>> dirn = {
        {1, 0},  // Down
        {0, 1},  // Right
        {-1, 0}, // Up
        {0, -1}, // Left
    };

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Priority queue for Dijkstra's algorithm
        // Stores {steps (obstacles removed), {current row, current column}}
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // Visited array to track already processed cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Start from the top-left corner
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int steps = top.first;     // Obstacles removed so far
            int i = top.second.first;  // Current row
            int j = top.second.second; // Current column

            // If we've reached the bottom-right corner, return the result
            if (i == n - 1 && j == m - 1)
                return steps;

            // Mark the current cell as visited
            if (visited[i][j])
                continue;
            visited[i][j] = true;

            // Explore all four possible directions
            for (auto it : dirn)
            {
                int x = i + it.first;  // New row
                int y = j + it.second; // New column

                // Check if the new position is within bounds and not visited
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y])
                {
                    // If the next cell is an obstacle, increment the steps
                    if (grid[x][y] == 1)
                        pq.push({steps + 1, {x, y}});
                    else // Otherwise, continue without incrementing steps
                        pq.push({steps, {x, y}});
                }
            }
        }

        return -1; // If there's no valid path, return -1
    }
};

int main()
{

    return 0;
}