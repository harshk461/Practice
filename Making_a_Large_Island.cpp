#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int d[5] = {1, 0, -1, 0, 1}; // Direction vectors for moving up, down, left, and right
    int n;                       // Grid size

    // Depth-First Search (DFS) to explore the island and calculate its size
    int dfs(int row, int col, int id, vector<vector<int>> &grid)
    {
        grid[row][col] = id; // Mark the cell with a unique island ID
        int cnt = 1;         // Initialize island size

        // Explore all 4 possible directions (up, down, left, right)
        for (int i = 0; i < 4; i++)
        {
            int nr = row + d[i];     // New row index
            int nc = col + d[i + 1]; // New column index

            // Check if the next cell is within bounds and is part of the same island
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1)
                cnt += dfs(nr, nc, id, grid); // Recursively explore the island
        }

        return cnt; // Return the total island size
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<int> key; // Stores sizes of all islands (indexed by island ID - 2)
        int id = 2;      // Start island IDs from 2 (to distinguish from water and unvisited land)

        // First pass: Identify and label all islands while calculating their sizes
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)                      // Found unvisited land
                    key.push_back(dfs(i, j, id++, grid)); // Assign ID and calculate island size
            }
        }

        if (key.empty())
            return 1; // If there are no islands, converting one water cell gives size 1

        int ans = 1; // Default answer (minimum island size if no merging happens)

        // Second pass: Check each water cell to see the maximum island size it can create
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {                // Found a water cell
                    int cnt = 1; // Start with size 1 (as we flip this water cell to land)

                    // Use a set to track unique neighboring islands (to avoid double counting)
                    unordered_set<int> visitedIslands;

                    // Check all 4 neighboring cells
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = i + d[k];
                        int nc = j + d[k + 1];

                        // Ensure the neighboring cell is valid and part of an island
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1)
                        {
                            int islandId = grid[nr][nc] - 2; // Convert grid ID to index in `key` vector
                            if (visitedIslands.find(islandId) == visitedIslands.end())
                            {
                                cnt += key[islandId];            // Add island size
                                visitedIslands.insert(islandId); // Mark island as counted
                            }
                        }
                    }

                    ans = max(ans, cnt); // Update the largest possible island size
                }
            }
        }

        return ans == 1 ? n * n : ans; // If no water cells were found, return n * n (entire grid is land)
    }
};

int main()
{

    return 0;
}