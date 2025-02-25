#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    // Speed up input/output operations for competitive programming
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    cin.tie(0);                  // Untie cin from cout
    cout.tie(0);                 // Untie cout from other streams
    return 'c';
}();

class Solution
{
public:
    // Direction vectors to explore 4 neighbors (right, left, down, up)
    vector<pair<int, int>> dirn = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();    // Number of rows in the grid
        int m = isWater[0].size(); // Number of columns in the grid

        // Initialize heights grid with -1 (unvisited cells)
        vector<vector<int>> heights(n, vector<int>(m, -1));

        queue<pair<int, int>> q; // Queue for BFS

        // Add all water cells to the queue and set their heights to 0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j])
                {
                    q.push({i, j});    // Push the cell into the queue
                    heights[i][j] = 0; // Water cells have a height of 0
                }
            }
        }

        int height_of_next_level = 1; // Start BFS with height level 1

        // Perform BFS to calculate the height of all land cells
        while (!q.empty())
        {
            int size = q.size(); // Number of elements at the current BFS level
                                 // isme phele sare 0 wale aayenge kyunki phele q.size() tak run karenge jisse sare zero wale traverse ho jayenge
                                 // phir 1 height wale
                                 // phir 2
                                 // aese krte krte 0 height(water cell) se bahar ki taraf jayenge height+1 krte hue jisse max difference between heights 1 rahe
            for (int i = 0; i < size; i++)
            {
                auto top = q.front(); // Get the front cell
                q.pop();

                // Explore all 4 neighbors
                for (auto it : dirn)
                {
                    int x = top.first + it.first;   // Neighbor row index
                    int y = top.second + it.second; // Neighbor column index

                    // Check if the neighbor is within bounds and unvisited
                    if (x >= 0 && x < n && y >= 0 && y < m && heights[x][y] == -1)
                    {
                        heights[x][y] = height_of_next_level; // Set the height
                        q.push({x, y});                       // Push neighbor into the queue
                    }
                }
            }
            height_of_next_level++; // Increment the height for the next level
        }

        return heights; // Return the computed heights grid
    }
};

int main()
{

    return 0;
}