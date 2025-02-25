#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C I/O streams for faster input/output.
    cin.tie(0);                  // Untie cin from cout to improve performance.
    cout.tie(0);                 // Untie cout from cin to improve performance.
    return 'c';
}();

// height,{row,col}
typedef pair<int, pair<int, int>> pi; // Custom data type to store height along with row and column indices.

class Solution
{
public:
    vector<pair<int, int>> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Directions for moving in 4 possible ways (down, right, up, left).

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size();
        if (n == 0)
            return 0; // Return 0 if the matrix is empty.
        int m = heightMap[0].size();
        if (m == 0)
            return 0; // Return 0 if the matrix has no columns.

        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix to keep track of visited cells.

        // Min-heap to store cells by height in ascending order.
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // Add all boundary cells to the min-heap and mark them as visited.
        for (int i = 0; i < n; i++)
        {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][0] = 1;
            vis[i][m - 1] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[n - 1][i], {n - 1, i}});
            vis[0][i] = 1;
            vis[n - 1][i] = 1;
        }

        int ans = 0; // Variable to store the total amount of trapped water.
        while (!pq.empty())
        {
            auto top = pq.top(); // Get the cell with the smallest height.
            pq.pop();

            int curr_h = top.first;    // Current height of the cell.
            int i = top.second.first;  // Row index of the cell.
            int j = top.second.second; // Column index of the cell.

            // Explore all 4 possible directions from the current cell.
            for (auto &it : dirn)
            {
                int x = i + it.first;  // New row index.
                int y = j + it.second; // New column index.

                // Check if the new cell is within bounds and not visited.
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
                {
                    int nbr_h = heightMap[x][y]; // Height of the neighboring cell.

                    if (nbr_h < curr_h)
                        ans += curr_h - nbr_h; // Water can be trapped if the neighbor is lower than the current cell.

                    pq.push({max(nbr_h, curr_h), {x, y}}); // Add the neighbor to the heap with the maximum height between the neighbor and the current cell.
                    vis[x][y] = 1;                         // Mark the neighbor as visited.
                }
            }
        }

        return ans; // Return the total trapped water.
    }
};

int main()
{

    return 0;
}